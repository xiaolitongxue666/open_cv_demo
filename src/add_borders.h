/* File: add_borders.h */
/* Author: xiaoli */
/* Date: Sat May 16 15:06:43 CST 2020 */
#ifndef _ADD_BORDERS_H_
#define _ADD_BORDERS_H_

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int AddImageBordersWithConstantColor(Mat SrcImage, Mat & DstImage, const Scalar & 	ColourRGBValue = Scalar());


#endif
