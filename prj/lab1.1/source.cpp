#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img = Mat::zeros(120, 768, CV_8UC1);
	for (int i = 3; i < img.cols; i += 3) 
	{
		img(Rect(i, 0, 768 - i, 60)) += 1;
	}
	Mat imgConvert;
	img.convertTo(img, CV_32FC1, 1.0/255.0);
	Rect rect1 = Rect(0, 0, 768, 60);
	Rect rect2 = Rect(0, 60, 768, 60);
	pow(img(rect1), 2.4, img(rect2));
	img.convertTo(img, CV_8UC1, 255.0);
	imshow("", img);
	waitKey(0);
	return 0;
}