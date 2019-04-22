#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){

    //Read the image
    Mat image = imread("../assets/putin.jpg");

    Mat imageYcb;

    //convert to YCrCb color space
    cvtColor(image, imageYcb, COLOR_BGR2YCrCb);

    //convert to float32
    imageYcb.convertTo(imageYcb, CV_32F);

    vector<Mat> channels(3);

    //split the channels
    split(imageYcb, channels);
    
    //declare scale factor
    float alpha = 0.5;

    //scale the Y channe;
    channels[0] = channels[0] * alpha;

    //clipping operation to limit pixel values between 0 and 255
    min(channels[0], 255, channels[0]);
    max(channels[0], 0, channels[0]);

    //Merge the channels
    merge(channels, imageYcb);

    //convert back from float32
    imageYcb.convertTo(imageYcb, CV_8UC3);

    //convert back to BGR color space
    Mat result;
    cvtColor(imageYcb, result, COLOR_YCrCb2BGR);

    //create windows to display images
    namedWindow("image", WINDOW_NORMAL);
    namedWindow("result", WINDOW_NORMAL);

    //display images
    imshow("image", image);
    imshow("result", result);

    //Press esc to exit the program
    waitKey(0);

    //close all the opended windows
    destroyAllWindows();

    return 0;
}