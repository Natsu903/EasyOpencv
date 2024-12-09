#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

float w = 250, h = 350;
Mat matrix, imgWarp;

int main(int argc, char* argv[])
{
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp,matrix,Point(w,h));

	for (auto & i : src)
	{
		circle(img, i, 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("imgWarp", imgWarp);
	waitKey(0);
	return 0;
}
