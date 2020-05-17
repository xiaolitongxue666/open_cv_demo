#include "show_img.h"
#include "resize_img.h"
#include "threshold_img.h"
#include "erosion_and_dilation.h"
#include "detect_skew_angle.h"
#include "rotation_image.h"
#include "add_borders.h"
#include "extract_tables.h"

int main(int argc,char *argv[])
{
    //Read a original image
#if 1
    Mat OriginalImage;
    cout << "Read original image unchanged" << endl;
    OriginalImage = imread(argv[1], IMREAD_UNCHANGED);
    if( !OriginalImage.data )
    {
        cout << "Read a image fail !" << endl;
        return -1;
    }
    ShowImage(OriginalImage, "Original Image");
#endif

    /* -------------------------------------------------------------- */

    //Resize a image
#if 0
    Mat ResizeImage;
    cout << "Resize original image" << endl;
    ResizeImage = ResizeImg(OriginalImage, 0.5, 0.5);//Scaling method
    ShowImage(ResizeImage, "Resize Image");
#endif

    /* -------------------------------------------------------------- */

    //Use threshold and show the difference
#if 0
    //ShowImageWithThresholdControl(OriginalImage);//Use this function to choose adjust parameter
    Mat GrayImage;
    Mat ThresholdImage;
    Mat &ImageQuote = ThresholdImage;
    cvtColor( OriginalImage, GrayImage, COLOR_BGR2GRAY ); // Convert the image to gray
    ShowImage(GrayImage, "Gray Image");
    ThresholdImg(GrayImage, ImageQuote, 174, 255, THRESH_BINARY_INV);
    ShowImage(ThresholdImage, "Threshold Image");
#endif

    /* -------------------------------------------------------------- */

    //Use erosion and dilation and show the difference
#if 0
    cout << "Read original image in color" << endl;
    OriginalImage = imread(argv[1], IMREAD_COLOR);
    if( !OriginalImage.data )
    {
        cout << "Read a color image fail !" << endl;
        return -1;
    }
    ShowImageWithErosionAndDilationControl( OriginalImage );//Use this function to choose adjust parameter
    Mat ErosionSrcImage;
    Mat DilationSrcImage;
    Mat &ErosionImageQuote = ErosionSrcImage;
    Mat &DilationImageQuote = DilationSrcImage;
    Erode(OriginalImage, ErosionImageQuote, 0, 0);
    ShowImage(ErosionSrcImage, "Erosion Image");
    Dilate(OriginalImage, DilationImageQuote, 0, 0);
    ShowImage(DilationSrcImage, "Dilation Image");
#endif

    /* -------------------------------------------------------------- */

    //Rotation image
#if 0
    Detect image skew angle and rotation it
    double SkewAngle = CalculateSkew(OriginalImage);
    RotationImage(OriginalImage, SkewAngle);
#endif

    /* -------------------------------------------------------------- */

    //Add borders
#if 0
    Mat OriginalImage;
    cout << "Read original image color" << endl;
    OriginalImage = imread(argv[1], IMREAD_COLOR);
    if( !OriginalImage.data )
    {
        cout << "Read a image fail !" << endl;
        return -1;
    }
    ShowImage(OriginalImage, "Original image in color");

    Mat DstImage;
    Mat &DstImageQuote = DstImage;
    Scalar ColorRGBValue( 0, 0, 0);
    AddImageBordersWithConstantColor(OriginalImage, DstImageQuote, ColorRGBValue);
    ShowImage(DstImageQuote, "Add borders image");

#endif

    /* -------------------------------------------------------------- */

    //Extract tables
#if 1
    ExtractTables(OriginalImage);
#endif

    /* -------------------------------------------------------------- */

    return 0;
}