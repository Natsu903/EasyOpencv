#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//缩放和裁剪图像

int main(int argc, char* argv[])
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgresize,imgCrop;

	//调整大小
	resize(img, imgresize, Size(640, 480));

	Rect roi(100, 100, 300, 250);
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("imgresize", imgresize);
	imshow("imgCrop", imgCrop);
	waitKey(0);
	return 0;
}