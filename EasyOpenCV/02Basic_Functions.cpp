#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//最基本的五个函数
void main()
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray,imgBlur,imgCanny, imgDil,imgErode;
	//转灰度图像
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	//高斯模糊
	GaussianBlur(imgGray, imgBlur,Size(3,3),5,0);
	//轮廓检测
	Canny(imgBlur, imgCanny, 25, 75);

	//图像的膨胀和腐蚀
	//用于创建可以使用的膨胀内核
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);

	//imshow("img", img);
	//imshow("imgGray", imgGray);
	//imshow("imgBlur", imgBlur);
	imshow("imgCanny", imgCanny);
	imshow("imgDil", imgDil);
	imshow("imgErode", imgErode);



	waitKey(0);
}