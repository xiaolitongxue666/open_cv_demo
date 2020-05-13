/* File: threshold_img.cpp */
/* Author: xiaoli */
/* Date: Mon May 11 23:43:35 CST 2020 */
#include "threshold_img.h"

double ThresholdImg(Mat SrcImage, Mat & DstImage, double Threshold, double MaxThreshold, int ThresholdType)
{
    return threshold(SrcImage, DstImage, Threshold, MaxThreshold, ThresholdType);
}