import cv2
import numpy as np

#Read the image
image = cv2.imread("../assets/putin.jpg")

#convert to YCrCb color space
imageYcb = cv2.cvtColor(image, cv2.COLOR_BGR2YCrCb)

#convert to float32
imageYcb =  np.float32(imageYcb)

#split into channels
Y, C, B = cv2.split(imageYcb)

#define scale factor
alpha = 1.5

#scale the Y channel
Y = Y * alpha

#clip the values betweeen 0 and 255
Y = np.clip(Y, 0, 255)

#merge the channels
imageYcb = cv2.merge([Y, C, B])

#convert back from float32
imageYcb = np.uint8(imageYcb)

#convert back to BGR color space
result = cv2.cvtColor(imageYcb, cv2.COLOR_YCrCb2BGR)

#create windows to display images
cv2.namedWindow("image", cv2.WINDOW_NORMAL)
cv2.namedWindow("result", cv2.WINDOW_NORMAL)

#display image
cv2.imshow("image", image)
cv2.imshow("result", result)

#press esc to exit the program
cv2.waitKey(0)

#close all the opended windows
cv2.destroyAllWindows()