# import the necessary packages
from imutils.face_utils import FaceAligner
from imutils.face_utils import rect_to_bb
import argparse
import imutils
import dlib
import cv2
import os

# construct the argument parser and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-p", "--shape-predictor", required=True,
help="path to facial landmark predictor")
ap.add_argument("-i", "--path", required=True,
help="path to input image")
ap.add_argument("-iw", "--image_width", type=int, default=800)
ap.add_argument("-fw", "--face_width", type=int, default=256)
args = vars(ap.parse_args())

# initialize dlib's face detector (HOG-based) and then create
# the facial landmark predictor and the face aligner
detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor(args["shape_predictor"])
fa = FaceAligner(predictor, desiredFaceWidth=args["face_width"])

try:
	os.mkdir(os.path.join(args["path"], "export"))
except Exception as e:
	print(e)

# load the input image, resize it, and convert it to grayscale
file_list = [f for f in os.listdir(args["path"]) if os.path.isfile(os.path.join(args["path"], f))]
print(file_list)
for img_num, this_img in enumerate(file_list):

	image = cv2.imread(os.path.join(args["path"], this_img))
	image = imutils.resize(image, width=args["image_width"])
	gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
	# show the original input image and detect faces in the grayscale
	# image
	# cv2.imshow("Input", image)
	rects = detector(gray, 2)

	# loop over the face detections
	for rect_num, rect in enumerate(rects):
		# extract the ROI of the *original* face, then align the face
		# using facial landmarks
		(x, y, w, h) = rect_to_bb(rect)
		faceOrig = imutils.resize(image[y:y + h, x:x + w], width=args["face_width"])
		faceAligned = fa.align(image, gray, rect)
		# display the output images
		# cv2.imshow("Original", faceOrig)
		cv2.imshow("Aligned", faceAligned)

		cv2.imwrite(os.path.join(args["path"], "export") + "/{0}-{1}.png".format(this_img, rect_num), faceAligned)

		cv2.waitKey(10)