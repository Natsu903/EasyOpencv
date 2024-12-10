#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//边框检测
void getContours(Mat& imgDil,Mat& img)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1,Scalar(225,0,225),2);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objectType;

	for (int i=0;i<contours.size();i++)
	{
		auto area = contourArea(contours[i]);
		cout << area << endl;
		//筛选面积小于1000的噪点
		if (area > 1000)
		{
			auto peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri,true);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			//cout << boundRect[i].size() << endl;
			int objCor = (int)conPoly[i].size();
			if (objCor == 3) { objectType = "Tri"; }
			if (objCor == 4) 
			{ 
				double aspRatio = (double)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) 
				{ 
					objectType = "Square"; 
				}
				else 
				{
					objectType = objectType = "Rect";
				}
			}
			if (objCor > 4) { objectType = "Circle"; }

			drawContours(img, conPoly, i, Scalar(225, 0, 225), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 225, 0), 5);
			putText(img, objectType,{boundRect[i].x,boundRect[i].y}, FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255), 1);
			
		}
	}
}

int main(int argc, char* argv[])
{
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	

	//预处理图像
	Mat imgGray, imgBlur, imgCanny, imgDil;
	//转灰度图像
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	//高斯模糊
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 5, 0);
	//轮廓检测
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil,img);

	imshow("Image", img);
	//imshow("imgGray", imgGray);
	//imshow("imgBlur", imgBlur);
	//imshow("imgCanny", imgCanny);
	//imshow("imgCanny", imgCanny);
	//imshow("imgDil", imgDil);
	
	waitKey(0);
	return 0;
}
