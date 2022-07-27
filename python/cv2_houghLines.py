import cv2
import numpy as np
import math


file = "/home/dav/IS-2021_/DCIM/20211016_Egilsstaðir-Autofahrt/IMGP2404_SonnenblendeShiftBlur.AVI"

cap = cv2.VideoCapture(file)
ret, frame = cap.read()

fps= int(cap.get(cv2.CAP_PROP_FPS))

print("This is the fps ", fps)

if cap.isOpened() == False:
    print("Error File Not Found")

while(cap.isOpened()):

    ret, frame = cap.read()

    if ret == True:

        gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray,50,150,apertureSize = 5)

        lines = cv2.HoughLines(edges,1,np.pi/180,200)
        if lines is not None:
            for rho,theta in lines[0]:
                a = np.cos(theta)
                b = np.sin(theta)
                x0 = a*rho
                y0 = b*rho
                x1 = int(x0 + 1000*(-b))
                y1 = int(y0 + 1000*(a))
                x2 = int(x0 - 1000*(-b))
                y2 = int(y0 - 1000*(a))

                cv2.line(frame,(x1,y1),(x2,y2),(0,0,255),2)


        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        cv2.imshow('frame', frame)
        cv2.imshow('edges', edges)

    else:
        break

cap.release()