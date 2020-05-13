/* File: show_img.cpp */
/* Author: xiaoli */
/* Date: Sat May  9 22:23:55 CST 2020 */
#include "show_img.h"
#include "threshold_img.h"

void ShowImage(Mat Image, const String & WindowName)
{
    if( !Image.data )
    {
        cout << "Input image error !" << endl;
        return ;
    }
    namedWindow(WindowName, WINDOW_NORMAL);
    imshow(WindowName, Image);
    waitKey(0);
}


int ThresholdValue = 0;
int ThresholdType = THRESH_TOZERO ;
int ThresholdValueMax = 255;
int ThresholdTypeMax = THRESH_TOZERO_INV ;
int BinaryValueMax = 255;
Mat SrcGrayImage;

static void ThresholdDemo( int, void* )
{
    /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
     Recommend: Type is THRESH_BINARY_INV(1) and value is 174 for OCR.
     */

    Mat Dst;

    cout << "Threshold image in type " << ThresholdType << " and value " <<  ThresholdValue << endl;

    threshold( SrcGrayImage, Dst, ThresholdValue, BinaryValueMax, ThresholdType );
    ShowImage( Dst, "Threshold image" );
}

void ShowImageWithThresholdControl(Mat Image)
{
    const char* TrackBarType = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
    const char* TrackBarValue = "Value";

    cvtColor( Image, SrcGrayImage, COLOR_BGR2GRAY ); // Convert the image to Gray
    namedWindow( "Threshold image", WINDOW_NORMAL ); // Create a window to display results
    createTrackbar( TrackBarType,"Threshold image", &ThresholdType,ThresholdTypeMax, ThresholdDemo ); // Create a TrackBar to choose type of Threshold
    createTrackbar( TrackBarValue,"Threshold image", &ThresholdValue,ThresholdValueMax, ThresholdDemo ); // Create a TrackBar to choose Threshold value
    ThresholdDemo( 0, 0 ); // Call the function to initialize
}


Mat ErosionAndDilationSrcImage, ErosionImage, DilationImage;
int ErosionElement = 0;
int ErosionSize = 0;
int DilationElement = 0;
int DilationSize = 0;
int const MaxElement = 2;
int const MaxKernelSize = 21;

void ErosionDemo( int, void* )
{
    int ErosionType = 0;
    if( ErosionElement == 0 ){ ErosionType = MORPH_RECT; }
    else if( ErosionElement == 1 ){ ErosionType = MORPH_CROSS; }
    else if( ErosionElement == 2) { ErosionType = MORPH_ELLIPSE; }
    Mat Element = getStructuringElement( ErosionType,
                                         Size( 2*ErosionSize + 1, 2*ErosionSize+1 ),
                                         Point( ErosionSize, ErosionSize ) );
    erode( ErosionAndDilationSrcImage, ErosionImage, Element );

    cout << "Erosion image in type " << ErosionType << " and size " <<  ErosionSize << endl;

    imshow( "Erosion Demo", ErosionImage );
}
void DilationDemo( int, void* )
{
    int DilationType = 0;
    if( DilationElement == 0 ){ DilationType = MORPH_RECT; }
    else if( DilationElement == 1 ){ DilationType = MORPH_CROSS; }
    else if( DilationElement == 2) { DilationType = MORPH_ELLIPSE; }
    Mat Element = getStructuringElement( DilationType,
                                         Size( 2*DilationSize + 1, 2*DilationSize+1 ),
                                         Point( DilationSize, DilationSize ) );
    dilate( ErosionAndDilationSrcImage, DilationImage, Element );

    cout << "Dilation image in type " << DilationType << " and size " <<  DilationSize << endl;

    imshow( "Dilation Demo", DilationImage );
}

void ShowImageWithErosionAndDilationControl( Mat Image )
{
    ErosionAndDilationSrcImage = Image;
    namedWindow( "Erosion Demo", WINDOW_NORMAL );
    namedWindow( "Dilation Demo", WINDOW_NORMAL );
    moveWindow( "Dilation Demo", Image.cols, 0 );
    createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
                    &ErosionElement, MaxElement,
                    ErosionDemo );
    createTrackbar( "Kernel size:\n 2n +1", "Erosion Demo",
                    &ErosionSize, MaxKernelSize,
                    ErosionDemo );
    createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
                    &DilationElement, MaxElement,
                    DilationDemo );
    createTrackbar( "Kernel size:\n 2n +1", "Dilation Demo",
                    &DilationSize, MaxKernelSize,
                    DilationDemo );
    ErosionDemo( 0, 0 );
    DilationDemo( 0, 0 );
    waitKey(0);
}
