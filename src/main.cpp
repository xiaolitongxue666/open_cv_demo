#include "show_img.h"
#include "resize_img.h"
#include "threshold_img.h"
#include "erosion_and_Dilation.h"

int main(int argc,char *argv[])
{
    Mat OriginalImage;

    //Read original image
    cout << "Read original image unchanged" << endl;
    OriginalImage = imread(argv[1], IMREAD_UNCHANGED);
    if( !OriginalImage.data )
    {
        cout << "Read a image fail !" << endl;
        return -1;
    }
    else
    {
        cout << "Read a image success ." << endl;
    }

    //Show a image
    cout << "Show original image" << endl;
    ShowImage(OriginalImage, "Original Image");

    //Resize a image
    //Mat ResizeImage;
    //cout << "Resize original image" << endl;
    //ResizeImage = ResizeImg(OriginalImage, 0.5, 0.5);

    //Show resize image
    //cout << "Show resize image" << endl;
    //ShowImage(ResizeImage, "Resize Image");

    //Change image threshold and show the difference
    //ShowImageWithThresholdControl(OriginalImage);//test
    Mat GrayImage;
    Mat ThresholdImage;
    Mat &ImageQuote = ThresholdImage;
    cvtColor( OriginalImage, GrayImage, COLOR_BGR2GRAY ); // Convert the image to Gray
    //ShowImage(GrayImage, "Gray Image");
    ThresholdImg(GrayImage, ImageQuote, 174, 255, THRESH_BINARY_INV);
    ShowImage(ThresholdImage, "Threshold Image");

    //Change erosion and dilation and show the difference
    //cout << "Read original image in color" << endl;
    //OriginalImage = imread(argv[1], IMREAD_COLOR);
    //if( !OriginalImage.data )
    //{
    //    cout << "Read a image fail !" << endl;
    //    return -1;
    //}
    //else
    //{
    //    cout << "Read a image success ." << endl;
    //}
    //ShowImageWithErosionAndDilationControl( OriginalImage );//test
    Mat ErosionSrcImage;
    Mat DilationSrcImage;
    Mat &ErosionImageQuote = ErosionSrcImage;
    Mat &DilationImageQuote = DilationSrcImage;
    Erode(OriginalImage, ErosionImageQuote, 0, 0);
    ShowImage(ErosionSrcImage, "Erosion Image");
    Dilate(OriginalImage, DilationImageQuote, 0, 0);
    ShowImage(DilationSrcImage, "Dilation Image");

    return 0;
}