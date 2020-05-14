/* File: ErosionAndDilation.cpp */
/* Author: xiaoli */
/* Date: Wed May 13 23:21:52 CST 2020 */
#include "show_img.h"
#include "detect_skew_angle.h"

double CalculateSkew(Mat SrcImage)
{
	vector<Vec4i> Lines;

	//Change to grayscale
	Mat GrayImage;
	cvtColor(SrcImage, GrayImage, COLOR_BGR2GRAY);

	Size GrayImageSize = GrayImage.size();

	//Change to black background
	Mat BlackBackgroundImage;
	bitwise_not(GrayImage, BlackBackgroundImage);

	HoughLinesP(BlackBackgroundImage, Lines, 1, CV_PI / 180, 100, GrayImageSize.width / 2.f, 20);

    Mat DisplaySkewCorrectionLines(GrayImageSize, CV_8UC1, Scalar(0, 0, 0));
    double Angel = 0.;
    unsigned NumberOfLines = Lines.size();
    for (unsigned i = 0; i < NumberOfLines; ++i)
    {
        line(DisplaySkewCorrectionLines, Point(Lines[i][0], Lines[i][1]),
            Point(Lines[i][2], Lines[i][3]), Scalar(255, 0, 0));
        Angel += atan2((double)Lines[i][3] - Lines[i][1],
            (double)Lines[i][2] - Lines[i][0]);
    }
    Angel /= NumberOfLines;

    cout << "Image skew angle is " << Angel * 180 / CV_PI << endl;

    ShowImage(DisplaySkewCorrectionLines, "Skew correction image");

    return Angel * 180 / CV_PI;
}