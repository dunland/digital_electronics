#######################################################################
# python script for creating focus tracks for a video via opencv
# dunland, january 2022
############################## EXECUTION: #############################
# running the script (first time):
# press and hold left mouse button to capture mouse position and export
# them
# 
# re-running the script will load the exported positions and focus the
# image at those points
#######################################################################

import cv2
import pandas as pd

# global variables
frame_num = 0
mouse_positions = pd.DataFrame(columns=['frame_num', 'mouse_position'])
mouse_button_down = False
read_pos_from_file = False

# mouse callback:
def mouse_click(event, x, y, flags, param):
    global mouse_positions, frame_num, mouse_button_down
    if event == cv2.EVENT_LBUTTONDOWN:
        mouse_button_down = True
        print("click!")
    elif event == cv2.EVENT_MOUSEMOVE and mouse_button_down:  # mouse drag
        mouse_positions = mouse_positions.append(pd.Series([frame_num, (x,y)], index=mouse_positions.columns), ignore_index=True)
    elif event == cv2.EVENT_LBUTTONUP:
        mouse_button_down = False


file = "/home/dav/github/digital_electronics/python/meisenbebies.mp4"
cap = cv2.VideoCapture(file)
cv2.namedWindow('video')
cv2.setMouseCallback('video', mouse_click)  # bind mouseClick as callback function to 'video' window

try:
    mouse_positions = pd.read_csv('mouse_positions_export.csv')
    read_pos_from_file = True
except (Exception):
    print("could not find mouse_positions_export.csv - click on the video to create it")


while (cap.isOpened()):
    ret, frame = cap.read()

    if ret == True:
        cv2.waitKey(5)  # this determines the framerate
        cv2.imshow('video', frame)        
        frame_num += 1

    else:
        break

print(mouse_positions)
mouse_positions.to_csv('mouse_positions_export.csv', index=False)
cap.release()
