/* File: show_img.cpp */
/* Author: xiaoli */
/* Date: Sat May  9 22:23:55 CST 2020 */
#include "show_img.h"

void ShowImage(Mat Image, const String & WindowName)
{
    namedWindow(WindowName, WINDOW_AUTOSIZE);
    imshow(WindowName, Image);
    waitKey(0);
}