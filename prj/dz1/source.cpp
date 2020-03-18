#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat Mozaika(string nameWindow, Mat img) {
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
	Mat rIn[] = { Mat::zeros(img.cols,img.rows, CV_8UC1),Mat::zeros(img.cols,img.rows, CV_8UC1),rgbchannel[2] };
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


	return mainImg;
}

int main() {
	Mat img = imread("e://images//cubes.jpg");
	imwrite("e://images//cubes65.jpg", img, { (int)IMWRITE_JPEG_QUALITY, 65 });
	imwrite("e://images//cubes95.jpg", img, { (int)IMWRITE_JPEG_QUALITY, 95 });
	Mat img65 = imread("e://images//cubes65.jpg");
	Mat img95 = imread("e://images//cubes95.jpg");
	Mat main65 = Mozaika("65", img65);
	Mat main95 = Mozaika("95", img95);

	imshow("", (main95 - main65)*30);

	


	waitKey(0);
	return 0;
	
}
