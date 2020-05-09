/* File: resize_img.cpp */
/* Author: xiaoli */
/* Date: Sat May  9 23:19:57 CST 2020 */

#include "resize_img.h"

Mat ResizeImg(Mat Image, float ScaleX, float ScaleY)
{
    Mat ResizeImage;

    resize(Image, ResizeImage, Size(), ScaleX, ScaleY, INTER_NEAREST);

    return ResizeImage;
}