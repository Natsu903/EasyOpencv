#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//图像，视频，摄像头内容导入

////image
//void main()
//{
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	imshow("img", img);
//	waitKey(0);
//}

////video
//void main()
//{
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	for (;;)
//	{
//		cap.read(img);
//		imshow("img", img);
//		waitKey(1);
//	}
//}

//webcam
void main()
{
	VideoCapture cap(0);
	Mat img;

	for (;;)
	{
		cap.read(img);
		imshow("img", img);
		waitKey(1);
	}
}

