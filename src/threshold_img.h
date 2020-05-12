/* File: threshold_img.h */
/* Author: xiaoli */
/* Date: Mon May 11 23:43:39 CST 2020 */
#ifndef _THRESHOLD_IMG_H_
#define _THRESHOLD_IMG_H_

#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

double ThresholdImg(Mat SrcImage, Mat DstImage, double Threshold, double MaxThreshold, int ThresholdType);

#endif
