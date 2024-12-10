#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	string path = "Resources/test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty())
	{
		cout << "***faceCascade.load failed***" << endl;
	}
	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);
	for (auto face : faces)
	{
		rectangle(img, face.tl(),face.br(), Scalar(225, 0, 225), 3);
	}

	imshow("Image", img);
	waitKey(0);
	return 0;
}
