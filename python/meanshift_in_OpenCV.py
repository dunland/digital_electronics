# For iterative focus definition on a very unsteady video...
# This script performs a cv2 meanshift algorithm on a video to follow features
# The image's center point is either calculated using the meanshift algorithm
# and exported to 'image_centers.csv' or exported to a csv file (using meanshift).
# Alternatively, the csv file can be used to read from.
# 
# dunland, 2022-04

import numpy as np
import cv2
import pandas as pd
import datetime

x_loc, y_loc = -1, -1
track_window = None
frame_number = 0
mouse_tracking = False
file = "/home/dav/IS-2021_/DCIM/20211016_Egilsstaðir-Autofahrt/IMGP2404_SonnenblendeShiftBlur.AVI"
# file = "meisenbebies.mp4"
# file = "/home/dav/Videos/contrast.mp4"
DO_APPLY_MEANSHIFT = input('apply meanshift to export center points? (y): ') == 'y'

if DO_APPLY_MEANSHIFT:
    image_centers = []
    x_positions = []
    y_positions = []
else:
    input_file = input("define .csv-file to read from: ")
    image_centers = pd.read_csv(input_file)
    print("using file 'image_centers'.csv':\n", image_centers)

def mouseReact(event, x, y, flags, param):
    global x_loc, y_loc
    global track_window, mouse_tracking

    if event == cv2.EVENT_MOUSEMOVE:
        # constantly reset location of roi
        if mouse_tracking:
            print(x, y)
            x_loc, y_loc, width, height = x, y, 100, 50
            track_window = (x_loc, y_loc, width, height)

    if event == cv2.EVENT_LBUTTONDOWN:
        mouse_tracking = True
        # x_loc, y_loc, width, height = x, y, 100, 50
        # track_window = (x_loc, y_loc, width, height)

    if event == cv2.EVENT_LBUTTONUP:
        mouse_tracking = False

        print("click at", x,y)

def main():
    global file, x_loc, y_loc, track_window, image_centers, x_positions, y_positions, frame_number, mouse_tracking
    cap = cv2.VideoCapture(file)
    num_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
    print("video has {0} frames".format(num_frames))    

    # take first frame of the video
    ret, frame = cap.read()

    # setup initial location of window
    x_loc, y_loc, width, height = 479, 827, 100, 50
    # x_loc, y_loc, width, height = 1550, 407, 50, 50
    track_window = (x_loc, y_loc, width, height)

    # set up the ROI for tracking
    roi = frame[y_loc:y_loc+height, x_loc: x_loc+width]
    hsv_roi = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv_roi, np.array((0., 60., 32.)),
                    np.array((180., 255., 255)))
    roi_hist = cv2.calcHist([hsv_roi], [0], mask, [180], [0, 180])
    cv2.normalize(roi_hist, roi_hist, 0, 255, cv2.NORM_MINMAX)

    # Setup the termination criteria, either 10 iteration or move by atleast 1 pt
    term_crit = (cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 10, 1)
    term_crit = (cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 1, 10)
    # cv2.imshow('roi', roi)

    while(cap.isOpened()):

        ret, frame = cap.read()

        if ret == True:

            # ret, bin_img = cv2.threshold(frame, 127,255, cv2.THRESH_BINARY)
            # frame, contours, hierarchy = cv2.findContours(bin_img, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

            # cv2.imshow('bin_img', bin_img)

            # hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            # dst = cv2.calcBackProject([hsv], [0], roi_hist, [0, 180], 1)


            # line detection: 
            gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
            edges = cv2.Canny(gray,50,150,apertureSize = 5)

            # lines = cv2.HoughLines(edges,1,np.pi/180,200)
            # if lines is not None:
            #     for rho,theta in lines[0]:
            #         a = np.cos(theta)
            #         b = np.sin(theta)
            #         x0 = a*rho
            #         y0 = b*rho
            #         x1 = int(x0 + 1000*(-b))
            #         y1 = int(y0 + 1000*(a))
            #         x2 = int(x0 - 1000*(-b))
            #         y2 = int(y0 - 1000*(a))

            #         cv2.line(frame,(x1,y1),(x2,y2),(0,0,255),2)

            # apply meanshift to get the new location
            if DO_APPLY_MEANSHIFT:
                ret, track_window = cv2.meanShift(edges, track_window, term_crit)
                # Draw rectangle on image
                x_loc, y_loc, w, h = track_window
                # final_image = cv2.rectangle(frame, (x_loc, y_loc), (x_loc+w, y_loc+h), 255, 2)
                # final_image = cv2.resize(frame, (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)*2),int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)*2)), interpolation=cv2.INTER_AREA)
                final_image = frame

                # save center of image for later export:
                image_centers.append((x_loc, y_loc))
                x_positions.append(x_loc)  
                y_positions.append(y_loc)

            else:
                x_loc = image_centers.at[frame_number, 'x_positions']
                y_loc = image_centers.at[frame_number, 'y_positions']

                # Draw rectangle on image
                # final_image = cv2.rectangle(frame, (x_loc-width/2, y_loc-width/2), (x_loc+width/2, y_loc+height/2), 255, 2)
                final_image = frame

            # crop image
            extent = 1080
            # border_h = int(y_loc+extent)
            border_h = int(y_loc/2+extent)
            # border_w = int(x_loc+extent)
            border_w = int(extent)

            frame = cv2.copyMakeBorder(frame, border_h, border_h, border_w, border_w, cv2.BORDER_CONSTANT, None, value=0)
            crop_frame = frame[border_h+y_loc-extent:border_h+y_loc+height+extent, border_w+x_loc-extent:border_w+x_loc+width+extent]
            # final_image = cv2.rectangle(frame, (x, y_loc), (x+w, y_loc+h), 255, 3)

            cv2.waitKey(1)  # increase this to slow down video

            # cv2.imshow('dst', dst)
            cv2.imshow('source', final_image)
            cv2.imshow('crop_frame', crop_frame)

            cv2.setMouseCallback('source', mouseReact)
            
            # export frame:
            cv2.imwrite('export/{0}.jpg'.format(frame_number), crop_frame)

            k = cv2.waitKey(30) & 0xff
            if k == 27:
                break

            frame_number += 1

        else:
            break

    cap.release()

    if DO_APPLY_MEANSHIFT:
        date = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")
        pd.DataFrame({'x_positions': x_positions, 'y_positions': y_positions}).to_csv('image_centers_{0}.csv'.format(date), index=False)

def read_from_file():
    pass

main()