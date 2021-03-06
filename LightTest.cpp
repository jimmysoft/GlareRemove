// LightTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\imgproc.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\core.hpp"
#include "opencv2\photo.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char **argv)
{
	Mat src = imread("C:\\Users\\Administrator\\Desktop\\owl.jpg", CV_8UC3);
	Mat threshold, dst;
	
	Mat inpaintMask;

	dst = src.clone();
	
	for (int i = 0; i < 1; i++) {

		cv::threshold(dst, threshold, 250, 255, CV_THRESH_BINARY);

		//imshow("threshold", threshold);

		threshold.convertTo(inpaintMask, CV_8UC1);

		imshow("mask", inpaintMask);

		dilate(inpaintMask, inpaintMask, Mat(), Point(-1, -1), 1, 1, 1);

		inpaint(dst, inpaintMask, dst, 1, INPAINT_TELEA);
	}

	imshow("result", dst);

	waitKey(0);
	return 0;
}