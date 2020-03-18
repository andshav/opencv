#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;



int main() {
	Mat kernel1_matrix(3, 3, CV_8UC1);
	kernel1_matrix.at<uchar>(0, 0) = 0;
	kernel1_matrix.at<uchar>(1, 0) = 0;
	kernel1_matrix.at<uchar>(2, 0) = 0;
	kernel1_matrix.at<uchar>(0, 1) = 2;
	kernel1_matrix.at<uchar>(1, 1) = 0;
	kernel1_matrix.at<uchar>(2, 1) = 0;
	kernel1_matrix.at<uchar>(0, 2) = 1;
	kernel1_matrix.at<uchar>(1, 2) = 1;
	kernel1_matrix.at<uchar>(2, 2) = -1;

	Mat kernel2_matrix(3, 3, CV_8UC1);
	kernel1_matrix.at<uchar>(0, 0) = 1;
	kernel1_matrix.at<uchar>(1, 0) = 2;
	kernel1_matrix.at<uchar>(2, 0) = 1;
	kernel1_matrix.at<uchar>(0, 1) = 0;
	kernel1_matrix.at<uchar>(1, 1) = 0;
	kernel1_matrix.at<uchar>(2, 1) = 0;
	kernel1_matrix.at<uchar>(0, 2) = -1;
	kernel1_matrix.at<uchar>(1, 2) = -2;
	kernel1_matrix.at<uchar>(2, 2) = -1;

	int size = 200;
	int radius = 50;
	Mat mainImg(size*2, size*3, CV_8UC1);
	Rect rcRoi1 = Rect(0, 0, size, size);
	Rect rcRoi2 = Rect(size, 0, size, size);
	Rect rcRoi3 = Rect(size*2, 0, size, size);
	Rect rcRoi4 = Rect(0, size, size, size);
	Rect rcRoi5 = Rect(size, size, size, size);
	Rect rcRoi6 = Rect(size*2, size, size, size);

	Mat img1(size, size, CV_8UC1, Scalar(255));
	Mat img2(size, size, CV_8UC1, Scalar(127));
	Mat img3(size, size, CV_8UC1, Scalar(0));
	Mat img6(size, size, CV_8UC1, Scalar(255));
	Mat img4(size, size, CV_8UC1, Scalar(127));
	Mat img5(size, size, CV_8UC1, Scalar(0));
	circle(img1, Point(img1.cols / 2, img1.rows / 2), radius, Scalar(0),FILLED);
	circle(img2, Point(img1.cols / 2, img1.rows / 2), radius, Scalar(255), FILLED);
	circle(img3, Point(img1.cols / 2, img1.rows / 2), radius, Scalar(127), FILLED);
	circle(img4, Point(img1.cols / 2, img1.rows / 2), radius, Scalar(0), FILLED);
	circle(img5, Point(img1.cols / 2, img1.rows / 2), radius, Scalar(255), FILLED);
	circle(img6, Point(img1.cols / 2, img1.rows / 2), radius, Scalar(127), FILLED);

	img1.copyTo(mainImg(rcRoi1));
	img2.copyTo(mainImg(rcRoi2));
	img3.copyTo(mainImg(rcRoi3));
	img2.copyTo(mainImg(rcRoi4));
	img3.copyTo(mainImg(rcRoi5));
	img1.copyTo(mainImg(rcRoi6));
	img1 = mainImg(rcRoi1);
	Mat mainImgF1;
	Mat mainImgF2;
	imshow("mainImg", mainImg);
	filter2D(mainImg, mainImgF1, -1, kernel1_matrix);
	filter2D(mainImg, mainImgF2, -1, kernel2_matrix);


	imshow("mainImgF1", mainImgF1);
	imshow("mainImgF2", mainImgF2);
	


	waitKey(0);
	return 0;
	
}
