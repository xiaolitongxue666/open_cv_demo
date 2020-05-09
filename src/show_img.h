/* File: show_img.h */
/* Author: xiaoli */
/* Date: Sat May  9 22:24:02 CST 2020 */
#ifndef _SHOW_IMG_H_
#define _SHOW_IMG_H_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/cvstd.hpp>

using namespace std;
using namespace cv;

void ShowImage(Mat Image, const String & WindowName);

#endif
