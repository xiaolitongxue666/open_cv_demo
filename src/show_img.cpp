/* File: show_img.cpp */
/* Author: xiaoli */
/* Date: Sat May  9 22:23:55 CST 2020 */
#include "show_img.h"
#include "threshold_img.h"

int ThresholdValue = 0;
int ThresholdType = THRESH_TOZERO ;
int ThresholdValueMax = 255;
int ThresholdTypeMax = THRESH_TOZERO_INV ;
int BinaryValueMax = 255;
Mat SrcGrayImage;

void ShowImage(Mat Image, const String & WindowName)
{
    if( !Image.data )
    {
        cout << "Input image error !" << endl;
        return ;
    }
    namedWindow(WindowName, WINDOW_AUTOSIZE);
    imshow(WindowName, Image);
    waitKey(0);
}

static void ThresholdDemo( int, void* )
{
    /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
    */

    Mat Dst;

    threshold( SrcGrayImage, Dst, ThresholdValue, BinaryValueMax, ThresholdType );
    ShowImage( Dst, "Threshold image" );
}

void ShowImageWithThresholdControl(Mat Image)
{
    const char* TrackBarType = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
    const char* TrackBarValue = "Value";

    cvtColor( Image, SrcGrayImage, COLOR_BGR2GRAY ); // Convert the image to Gray
    namedWindow( "Threshold image", WINDOW_AUTOSIZE ); // Create a window to display results
    createTrackbar( TrackBarType,"Threshold image", &ThresholdType,ThresholdTypeMax, ThresholdDemo ); // Create a TrackBar to choose type of Threshold
    createTrackbar( TrackBarValue,"Threshold image", &ThresholdValue,ThresholdValueMax, ThresholdDemo ); // Create a TrackBar to choose Threshold value
    ThresholdDemo( 0, 0 ); // Call the function to initialize
}