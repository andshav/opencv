#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat hist(Mat img) {
	int hist[256] = { 0 };
	for (int i = 0; i < img.cols; i++)
	{
		for (int j = 0; j < img.rows; j++)
		{
			hist[img.at<uchar>(i, j)]++;
		}
	}
	int max = 0;
	for (int i = 0; i < 256; i++)
	{
		if (hist[i] > max) max = hist[i];
	}
	Mat imgHist = Mat::zeros(max, img.rows, IMREAD_GRAYSCALE);
	for (int i = max - 1; i >= 0; i--)
	{
		for (int j = 0; j < img.rows; j++)
		{
			if (max - 1 - i > hist[j]) imgHist.at<uchar>(i, j) = 255;
		}
	}
	resize(imgHist, imgHist, Size(256, 400), 0, 0);
	return imgHist;
}
int func(int x) {
	return abs(abs(2 * x + 100) - abs(4 * x - 300));
}
int main() {
	Mat img = imread("e://images//image.jpg", IMREAD_GRAYSCALE);
	Mat imgHist = hist(img);
	resize(imgHist, imgHist, Size(256, 400), 0, 0);
	imshow("imgHist1", imgHist);

	imshow("img1", img);
	for (int i = 0; i < img.cols; i++)
	{
		for (int j = 0; j < img.rows; j++)
		{
			img.at<uchar>(i, j) = func(img.at<uchar>(i, j));
		}
	}
	imgHist = hist(img);

	imshow("imgHist2", imgHist);
	imshow("img2", img);
	Mat graph(256, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++)
	{
		graph.at<uchar>(255-func(i), i) = 0;
	}

	imshow("graph", graph);
	waitKey(0);
	return 0;
}