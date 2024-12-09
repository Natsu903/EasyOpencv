#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//绘制形状和文字

int main(int argc, char* argv[])
{
	Mat img(512, 512, CV_8UC3,Scalar(255,0,255));
	//绘制圆形
	circle(img, Point(256,256), 155, Scalar(0, 156, 255),FILLED);
	//绘制矩形
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(225, 225, 225), FILLED);
	//绘制直线
	line(img, Point(130, 296), Point(382, 296), Scalar(225, 225, 225), 2);
	//绘制文字
	putText(img, "Hello", Point(137,262), FONT_HERSHEY_DUPLEX, 2, Scalar(0, 69,255), 2);
	imshow("img",img);
	waitKey(0);
	return 0;
}
