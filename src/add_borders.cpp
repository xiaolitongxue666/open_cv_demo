/* File: add_borders.cpp */
/* Author: xiaoli */
/* Date: Sat May 16 15:06:40 CST 2020 */

#include "show_img.h"
#include "add_borders.h"

int AddImageBordersWithConstantColor(Mat SrcImage, Mat & DstImage, const Scalar & ColourRGBValue)
{
    int Top, Bottom, Left, Right;

    // Initialize arguments for the filter
    Top = (int) (0.05*SrcImage.rows); Bottom = Top;
    Left = (int) (0.05*SrcImage.cols); Right = Left;

    copyMakeBorder( SrcImage, DstImage, Top, Bottom, Left, Right, BORDER_CONSTANT, ColourRGBValue );

    return 0;
}