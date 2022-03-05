import numpy as np
import cv2
from numpy.lib.polynomial import polyadd

play_video = False
x_loc, y_loc = -1, -1
MOUSE_POSITION = (0, 0)

def mousePosition(event, x, y, flags, param):
    global MOUSE_POSITION
    if event == cv2.EVENT_MOUSEMOVE:
        cv2.putText(final_image, str(x) + str(y), x, y, cv2.FONT_HERSHEY_COMPLEX, (255,0,255), 1, cv2.LINE_AA)
        MOUSE_POSITION = (x,y)

def mouseClick(event, x, y, flags, param):
    global x_loc, y_loc
    if event == cv2.EVENT_LBUTTONUP:
        print("click at", x,y)
        play_video = True
        param = (x,y)
        x_loc = x
        y_loc = y


# file = input("file:")
file = "meisenbebies.mp4"
file = "SonnenblendeShiftBlur-20211019.mp4"
cap = cv2.VideoCapture(file)

# take first frame of the video
ret, frame = cap.read()

# setup initial location of window
x_loc, y_loc, width, height = 435, 725, 100, 50
x_loc, y_loc, width, height = 1550, 407, 50, 50
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
        ret, track_window = cv2.meanShift(dst, track_window, term_crit)

        # Draw it on image
        x_loc, y_loc, w, h = track_window
        final_image = cv2.rectangle(frame, (x_loc, y_loc), (x_loc+w, y_loc+h), 255, 2)
        # final_image = cv2.resize(frame, (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)*2),int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)*2)), interpolation=cv2.INTER_AREA)

        # crop image
        extent = 300
        # border_h = int(y_loc+extent)
        border_h = int(y_loc/2+extent)
        # border_w = int(x_loc+extent)
        border_w = int(extent)

        frame = cv2.copyMakeBorder(frame, border_h, border_h, border_w, border_w, cv2.BORDER_CONSTANT, None, value=0)
        crop_frame = frame[border_h+y_loc-extent:border_h+y_loc+height+extent, border_w+x_loc-extent:border_w+x_loc+width+extent]
        # final_image = cv2.rectangle(frame, (x, y_loc), (x+w, y_loc+h), 255, 3)

        cv2.waitKey(20)

        # cv2.setMouseCallback('final_image', mousePosition)

        if cv2.waitKey == ' ':
            print(mousePosition)

        # cv2.imshow('dst', dst)
        cv2.imshow('final_image', final_image)
        cv2.imshow('crop_frame', crop_frame)
        k = cv2.waitKey(30) & 0xff
        if k == 27:
            break

        # cv2.setMouseCallback('final_image', mouseClick)

        # while(not play_video):
        #     cv2.setMouseCallback('final_image', start_video)

    else:
        break

cap.release()