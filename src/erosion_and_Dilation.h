/* File: ErosionAndDilation.h */
/* Author: xiaoli */
/* Date: Wed May 13 23:21:55 CST 2020 */
#ifndef _EROSION_ANDD_ILATION_H_
#define _EROSION_ANDD_ILATION_H_

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void Erode(Mat SrcImage, Mat & DstImage, int ErosionType, int ErosionSize);
void Dilate(Mat SrcImage, Mat & DstImage, int DilationType, int DilationSize);


#endif
