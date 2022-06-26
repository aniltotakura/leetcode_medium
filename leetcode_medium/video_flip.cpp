#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
int main(int argc, char* argv[]) {
   VideoCapture loadvideo("/home/anil/Badminton/IMG_2277.MOV");//capture video from default camera//
   namedWindow("OriginalVideo");//declaring window to show original video stream//
   namedWindow("RotatedVideo");//declaring window to show rotated video stream//
   int rotating_angle = 180;//initial rotation angle//
   createTrackbar("Rotation", "RotatedVideo", &rotating_angle, 360);//creating trackbar for rotation//
   while (true) {
      Mat before_Rotating;//declaring matrix for image before rotation//
      bool temp = loadvideo.read(before_Rotating);//load frames from video source to matrix//
      imshow("OriginalVideo", before_Rotating);//show image frames before rotation//
      Mat for_Rotation = getRotationMatrix2D(Point(before_Rotating.cols / 2, before_Rotating.rows / 2), (rotating_angle - 180), 1);//affine transformation matrix for the 2D rotation//
      Mat after_Rotating;//declaring matrix for image after rotation//
      warpAffine(before_Rotating, after_Rotating, for_Rotation, before_Rotating.size());//applying affine transformation//
      imshow("RotatedVideo", after_Rotating);//show image after rotating//
      if (waitKey(30) == 27){ //wait till Esc key is pressed from keyboard//
         break;
      }
   }
   return 0;
}