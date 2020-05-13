/* File: ErosionAndDilation.cpp */
/* Author: xiaoli */
/* Date: Wed May 13 23:21:52 CST 2020 */
#include "erosion_and_Dilation.h"

void Erode(Mat SrcImage, Mat & DstImage, int ErosionType, int ErosionSize)
{
    Mat Element = getStructuringElement( ErosionType,
                                         Size( 2*ErosionSize + 1, 2*ErosionSize+1 ),
                                         Point( ErosionSize, ErosionSize ) );
    erode( SrcImage, DstImage, Element );
}

void Dilate(Mat SrcImage, Mat & DstImage, int DilationType, int DilationSize)
{
    Mat Element = getStructuringElement( DilationType,
                                         Size( 2*DilationSize + 1, 2*DilationSize+1 ),
                                         Point( DilationSize, DilationSize ) );
    dilate( SrcImage, DstImage, Element );
}
