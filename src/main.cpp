#include "show_img.h"
#include "resize_img.h"

int main(int argc,char *argv[])
{
    Mat Image;

    //Read original image
    cout << "Read original image" << endl;
    Image = imread(argv[1], IMREAD_UNCHANGED);
    if( !Image.data )
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
    ShowImage(Image, "Original Image");

    //Resize a image
    Mat ResizeImage;
    cout << "Resize original image" << endl;
    ResizeImage = ResizeImg(Image, 0.5, 0.5);

    //Show resize image
    cout << "Show resize image" << endl;
    ShowImage(ResizeImage, "Resize Image");

    //Change image threshold and show the difference
    Image = imread(argv[1], IMREAD_UNCHANGED);
    ShowImageWithThresholdControl(Image);

    return 0;
}