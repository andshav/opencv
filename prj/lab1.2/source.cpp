#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	double gamma;
	cout << "Input gammaValue\n";
	cin >> gamma;
	Mat_<double> img = Mat::zeros(120, 768, IMREAD_GRAYSCALE);
	img(Rect(0, 0, 30, 60)) = 5.0 / 255.0;
	for (int i = 30; i < img.cols; i += 30)
	{
		img(Rect(i, 0, 768 - i, 60)) += 10.0 / 255.0;
	}
	Rect rect1 = Rect(0, 0, 768, 60);
	Rect rect2 = Rect(0, 60, 768, 60);
	pow(img(rect1), 1.0 / gamma, img(rect2));
	imshow("", img);
	waitKey(0);
	return 0;
}