/* File: resize_img.h */
/* Author: xiaoli*/
/* Date: Sat May  9 23:19:59 CST 2020 */
#ifndef _RESIZE_IMG_H_
#define _RESIZE_IMG_H_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat ResizeImg(Mat Image, float ScaleX, float ScaleY);

#endif
