#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("e://images//image.jpg");
	Mat mainImg = Mat::zeros(img.cols * 2, img.rows * 4, CV_8UC3);
	Mat rgbchannel[3];
	split(img, rgbchannel);
	Rect rcRoi1 = Rect(0, 0, img.rows, img.cols);
	Rect rcRoi2 = Rect(img.rows, 0, img.rows, img.cols);
	Rect rcRoi3 = Rect(img.rows * 2, 0, img.rows, img.cols);
	Rect rcRoi4 = Rect(img.rows * 3, 0, img.rows, img.cols);
	Rect rcRoi5 = Rect(img.rows, img.cols, img.rows, img.cols);
	Rect rcRoi6 = Rect(img.rows * 2, img.cols, img.rows, img.cols);
	Rect rcRoi7 = Rect(img.rows * 3, img.cols, img.rows, img.cols);
	img.copyTo(mainImg(rcRoi1));
	cout << rgbchannel[0].channels();

	Mat rchannel;
	Mat rchannelIn[] = { rgbchannel[2], rgbchannel[2], rgbchannel[2] };
	merge(rchannelIn, 3, rchannel);
	rchannel.copyTo(mainImg(rcRoi2));

	Mat gchannel;
	Mat gchannelIn[] = { rgbchannel[1] ,rgbchannel[1],rgbchannel[1] };
	merge(gchannelIn, 3, gchannel);
	gchannel.copyTo(mainImg(rcRoi3));

	Mat bchannel;
	Mat bchannelIn[] = { rgbchannel[0] ,rgbchannel[0],rgbchannel[0] };
	merge(bchannelIn, 3, bchannel);
	bchannel.copyTo(mainImg(rcRoi4));


	Mat r;
	Mat rIn[] = {  Mat::zeros(img.cols,img.rows, CV_8UC1),Mat::zeros(img.cols,img.rows, CV_8UC1),rgbchannel[2] };
	merge(rIn, 3, r);
	r.copyTo(mainImg(rcRoi5));

	Mat g;
	Mat gIn[] = { Mat::zeros(img.cols,img.rows, CV_8UC1), rgbchannel[1], Mat::zeros(img.cols,img.rows, CV_8UC1) };
	merge(gIn, 3, g);
	g.copyTo(mainImg(rcRoi6));

	Mat b;
	Mat bIn[] = { rgbchannel[0], Mat::zeros(img.cols,img.rows, CV_8UC1),Mat::zeros(img.cols,img.rows, CV_8UC1) };
	merge(bIn, 3, b);
	b.copyTo(mainImg(rcRoi7));


	imshow("", mainImg);
	


	waitKey(0);
	return 0;
	
}
