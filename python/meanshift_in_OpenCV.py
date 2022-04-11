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

play_video = False
x_loc, y_loc = -1, -1
track_window = None
DO_APPLY_MEANSHIFT = input('apply meanshift to export center points? (y): ') == 'y'

if DO_APPLY_MEANSHIFT:
    image_centers = []
    x_positions = []
    y_positions = []
else:
    frame_number = 0
    input_file = input("define .csv-file to read from: ")
    image_centers = pd.read_csv(input_file)
    print("using file 'image_centers'.csv':\n", image_centers)

def mouseReact(event, x, y, flags, param):
    global x_loc, y_loc
    global track_window

    if event == cv2.EVENT_MOUSEMOVE:
        print(x, y)

    if event == cv2.EVENT_LBUTTONDOWN:
        # reset location of roi
        x_loc, y_loc, width, height = x, y, 100, 50
        track_window = (x_loc, y_loc, width, height)

        print("click at", x,y)

def main():
    global play_video, x_loc, y_loc, track_window, image_centers, x_positions, y_positions, frame_number
    # file = input("file:")
    file = "meisencut.mp4"
    # file = "SonnenblendeShiftBlur-20211019.mp4"
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
    # cv2.imshow('roi', roi)

    while(cap.isOpened()):

        ret, frame = cap.read()

        if ret == True:

            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            dst = cv2.calcBackProject([hsv], [0], roi_hist, [0, 180], 1)

            # apply meanshift to get the new location
            if DO_APPLY_MEANSHIFT:
                ret, track_window = cv2.meanShift(dst, track_window, term_crit)

                # Draw rectangle on image
                x_loc, y_loc, w, h = track_window
                final_image = cv2.rectangle(frame, (x_loc, y_loc), (x_loc+w, y_loc+h), 255, 2)
                # final_image = cv2.resize(frame, (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)*2),int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)*2)), interpolation=cv2.INTER_AREA)

                # save center of image for later export:
                image_centers.append((x_loc, y_loc))
                x_positions.append(x_loc)  
                y_positions.append(y_loc)  

            else:
                # positions = tuple(map(int, image_centers.at[frame_number, 'center_points'].split(',')))
                # x_loc, y_loc = int(positions[0]), int(positions[1])
                x_loc = image_centers.at[frame_number, 'x_positions']
                y_loc = image_centers.at[frame_number, 'y_positions']
                frame_number += 1

                # Draw rectangle on image
                final_image = cv2.rectangle(frame, (x_loc, y_loc), (x_loc+width, y_loc+height), 255, 2)

            # crop image
            extent = 300
            # border_h = int(y_loc+extent)
            border_h = int(y_loc/2+extent)
            # border_w = int(x_loc+extent)
            border_w = int(extent)

            frame = cv2.copyMakeBorder(frame, border_h, border_h, border_w, border_w, cv2.BORDER_CONSTANT, None, value=0)
            crop_frame = frame[border_h+y_loc-extent:border_h+y_loc+height+extent, border_w+x_loc-extent:border_w+x_loc+width+extent]
            # final_image = cv2.rectangle(frame, (x, y_loc), (x+w, y_loc+h), 255, 3)

            cv2.waitKey(1)  # increase this to slow down video

            # cv2.imshow('dst', dst)
            cv2.imshow('final_image', final_image)
            cv2.imshow('crop_frame', crop_frame)

            cv2.setMouseCallback('final_image', mouseReact)
            
            k = cv2.waitKey(30) & 0xff
            if k == 27:
                break

            # cv2.setMouseCallback('final_image', mouseClick)

            # while(not play_video):
            #     cv2.setMouseCallback('final_image', start_video)

        else:
            break

    cap.release()

    if DO_APPLY_MEANSHIFT:
        date = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")
        pd.DataFrame({'x_positions': x_positions, 'y_positions': y_positions}).to_csv('image_centers_{0}.csv'.format(date), index=False)

def read_from_file():
    pass

main()