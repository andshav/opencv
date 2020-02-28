#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	double gamma;
	cout << "Input gammaValue\n";
	cin >> gamma;
	Mat_<float> img = Mat::zeros(120, 768, IMREAD_GRAYSCALE);
	for (int i = 3; i < img.cols; i += 3) 
	{
		img(Rect(i, 0, 768 - i, 60)) += 1.0/255.0;
	}
	Rect rect1 = Rect(0, 0, 768, 60);
	Rect rect2 = Rect(0, 60, 768, 60);
	pow(img(rect1), 1.0 / gamma, img(rect2));
	imshow("", img);
	waitKey(0);
	return 0;
}