import cv2
import numpy as np

video_path_1 = video_path_2 = "/home/dunland/kdenlive-projects/sturmUndDrang/VID_20231217_202600.mp4"

# Function to create a transparent overlay with inverted colors
def create_overlay(frame, alpha=0.5):
    inverted_frame = cv2.bitwise_not(frame)  # Invert colors
    overlay = np.zeros_like(frame)
    overlay[:] = (0, 255, 0)  # Set color (here, green)
    return cv2.addWeighted(overlay, alpha, inverted_frame, 1 - alpha, 0)

# Open the first video file
cap1 = cv2.VideoCapture(video_path_1)

# Open the second video file
cap2 = cv2.VideoCapture(video_path_2)

# Check if videos opened successfully
if not cap1.isOpened() or not cap2.isOpened():
    print("Error: Couldn't open one or both video files")
    exit()

# Get video properties
fps = cap1.get(cv2.CAP_PROP_FPS)
width = int(cap1.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap1.get(cv2.CAP_PROP_FRAME_HEIGHT))

# Create a VideoWriter object for the output
output_path = 'output_video.mp4'
fourcc = cv2.VideoWriter_fourcc(*'mp4v')
out = cv2.VideoWriter(output_path, fourcc, fps, (width, height))

# Adjustable parameter for repositioning the second video
frame_offset = 1
current_frame_offset = 1  # Initialize to 1 to start at frame 2

while True:
    # Read frames from the first video
    ret1, frame1 = cap1.read()
    if not ret1:
        break  # Break the loop if the first video is finished

    # Read frames from the second video with the offset
    ret2, frame2 = cap2.read()
    if not ret2:
        # If the second video is finished, rewind it
        cap2.set(cv2.CAP_PROP_POS_FRAMES, 0)
        current_frame_offset = 0  # Reset the frame offset
        continue

    # Increment the frame offset for the second video
    current_frame_offset += 1

    # If the current frame offset matches the desired offset, overlay the second video
    if current_frame_offset == frame_offset:
        overlay = create_overlay(frame2, alpha=0.5)
        combined_frame = cv2.addWeighted(frame1, 1, overlay, 1, 0)
    else:
        # Otherwise, use only the frame from the first video
        combined_frame = frame1

    # Display the combined frame
    cv2.imshow('Combined Video', combined_frame)
    out.write(combined_frame)  # Write the frame to the output video

    # Break the loop if 'q' key is pressed
    if cv2.waitKey(int(1000 / fps)) & 0xFF == ord('q'):
        break

# Release resources
cap1.release()
cap2.release()
out.release()
cv2.destroyAllWindows()
