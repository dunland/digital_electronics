# import the necessary packages
from imutils.face_utils import FaceAligner
from imutils.face_utils import rect_to_bb
from imutils.face_utils.helpers import FACIAL_LANDMARKS_68_IDXS
from imutils.face_utils.helpers import FACIAL_LANDMARKS_5_IDXS
from imutils.face_utils.helpers import shape_to_np


import argparse
import imutils
import dlib
import cv2
import os
import numpy as np

# construct the argument parser and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-p", "--shape-predictor", required=True,
help="path to facial landmark predictor")
ap.add_argument("-i", "--video", required=True,
help="path to input video")
ap.add_argument("-iw", "--image_width", type=int, default=800)
ap.add_argument("-fw", "--face_width", type=int, default=256)

args = vars(ap.parse_args())

export_folder = os.path.join(args["video"][:-4])
print("export to:" + export_folder)
try:
    os.mkdir(args["video"][:-4])
except Exception as e:
    print("Error!", e)


# initialize dlib's face detector (HOG-based) and then create
# the facial landmark predictor and the face aligner
detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor(args["shape_predictor"])
fa = FaceAligner(predictor, desiredFaceWidth=args["face_width"])

# load the input video, resize it, and convert it to grayscale
video = cv2.VideoCapture(args["video"])

# setup initial location of window
x_loc, y_loc, width, height = int(args["face_width"]), int(args["face_width"]), args["face_width"], args["face_width"]
# x_loc, y_loc, width, height = 1550, 407, 50, 50
track_window = (x_loc, y_loc, width, height)

ret, frame = video.read()

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


i = 0
while(video.isOpened()):
    ret, frame = video.read()
    if ret == True:

        print("working on frame", i)
        # frame = imutils.resize(frame, width=800)
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        # show the original input video and detect faces in the grayscale
        # video

        # cv2.imshow("Frame", frame)
        rects = detector(gray, 2)

        # loop over the face detections
        if len(rects) > 0:
            for rect in rects:
                # extract the ROI of the *original* face, then align the face
                # using facial landmarks
                (x, y, w, h) = rect_to_bb(rect)
                faceOrig = imutils.resize(frame[y:y + h, x:x + w], width=args["face_width"])
                faceAligned = fa.align(frame, gray, rect)
                # display the output videos
                # cv2.imshow("Original", faceOrig)
                cv2.imshow("Aligned", faceAligned)
                cv2.waitKey(10)

                cv2.imwrite(export_folder + "/{0}.png".format(i), faceAligned)

                # set track_window to eyesCenter:

                shape = fa.predictor(gray, rect)
                shape = shape_to_np(shape)

                #simple hack ;)
                if (len(shape)==68):
                    # extract the left and right eye (x, y)-coordinates
                    (lStart, lEnd) = FACIAL_LANDMARKS_68_IDXS["left_eye"]
                    (rStart, rEnd) = FACIAL_LANDMARKS_68_IDXS["right_eye"]
                else:
                    (lStart, lEnd) = FACIAL_LANDMARKS_5_IDXS["left_eye"]
                    (rStart, rEnd) = FACIAL_LANDMARKS_5_IDXS["right_eye"]

                leftEyePts = shape[lStart:lEnd]
                rightEyePts = shape[rStart:rEnd]

                leftEyeCenter = leftEyePts.mean(axis=0).astype("int")
                rightEyeCenter = rightEyePts.mean(axis=0).astype("int")

                track_window = (
                     int((leftEyeCenter[0] + rightEyeCenter[0]) // 2),
                     int((leftEyeCenter[1] + rightEyeCenter[1]) // 2),
                     width, height)

        else:
            gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
            edges = cv2.Canny(gray,50,150,apertureSize = 5)
            ret, track_window = cv2.meanShift(edges, track_window, term_crit)
            # Draw rectangle on image
            x_loc, y_loc, w, h = track_window
            # final_image = cv2.rectangle(frame, (x_loc, y_loc), (x_loc+w, y_loc+h), 255, 2)
            # final_image = cv2.resize(frame, (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)*2),int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)*2)), interpolation=cv2.INTER_AREA)
            final_image = frame

            # crop image
            extent = args["face_width"]
            # border_h = int(y_loc+extent)
            border_h = int(y_loc/2+extent)
            # border_w = int(x_loc+extent)
            border_w = int(extent)

            # frame = cv2.copyMakeBorder(frame, border_h, border_h, border_w, border_w, cv2.BORDER_CONSTANT, None, value=0)
            crop_frame = imutils.resize(frame[y:y + h, x:x + w], width=args["face_width"])
            final_image = cv2.rectangle(frame, (x, y_loc), (x+w, y_loc+h), 255, 3)

            cv2.waitKey(1)  # increase this to slow down video

            # cv2.imshow('dst', dst)
            cv2.imshow('source', final_image)
            cv2.imshow('crop_frame', crop_frame)

            # cv2.setMouseCallback('source', mouseReact)

            # export frame:
            cv2.imwrite(export_folder + "/{0}.png".format(i), crop_frame)

        i += 1


        # keyboard interrupt:
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break
    else:
        break

video.release()
cv2.destroyAllWindows()