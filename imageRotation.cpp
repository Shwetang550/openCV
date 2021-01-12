#include<opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("F:/openCV/download.jpg", IMREAD_UNCHANGED);
	double angle;
	cin >> angle;
	Point2f center((img.cols -1) / 2.0, (img.rows -1) / 2.0);
	Mat rot = getRotationMatrix2D(center, angle, 1.0);
	Rect2f bbox = RotatedRect(Point2f(), img.size(), angle).boundingRect2f();
	rot.at<double>(0, 2) += bbox.width / 2.0 - img.cols / 2.0;
	rot.at<double>(1, 2) += bbox.height / 2.0 - img.rows / 2.0;
	
	Mat X;
	warpAffine(img, X, rot, bbox.size());
	imwrite("rotated_image.png", X);
	string windowName = "Rotated Image";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, X);
	waitKey(0);
	destroyWindow(windowName);
	return 0;
}