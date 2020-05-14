/* File: ErosionAndDilation.cpp */
/* Author: xiaoli */
/* Date: Wed May 13 23:21:52 CST 2020 */
#include "rotation_image.h"

void RotationImage(Mat SrcImage, double angle)
{
	Mat GrayImage;
	cvtColor(SrcImage, GrayImage, COLOR_BGR2GRAY);
	bitwise_not(GrayImage, GrayImage);

	//Bounding BoundingBox
	vector<Point> ImagePoints;

	Mat_<uchar>::iterator it = GrayImage.begin<uchar>();
	Mat_<uchar>::iterator end = GrayImage.end<uchar>();

	for (; it != end; ++it)
		if (*it)
			ImagePoints.push_back(it.pos());

	RotatedRect BoundingBox = minAreaRect(Mat(ImagePoints));

	//Rotation
	/*
	 * Compute the rotation matrix using the corresponding OpenCV function,
	 * we specify the center of the rotation (the center of our bounding box),
	 * the rotation angle (the skew angle) and the scale factor (none here).
	 * */
	Mat RotationImage = getRotationMatrix2D(BoundingBox.center, angle, 1);

	Mat RotatedImage;
	warpAffine(GrayImage, RotatedImage, RotationImage, GrayImage.size(), INTER_CUBIC);

	//Crop the image in order to remove borders
	/*
	 * if the skew angle is positive,
	 * the angle of the bounding box is below -45 degrees,
	 * because the angle is given by taking as a reference a "vertical" rectangle,
	 * i.e. with the height greater than the width.
	 * Therefore, if the angle is positive, we swap height and width before calling the cropping function
	 * */
	Size BoundingBoxSize = BoundingBox.size;
	if (BoundingBox.angle < -45.)
		std::swap(BoundingBoxSize.width, BoundingBoxSize.height);
	Mat CoppedImage;
	getRectSubPix(RotatedImage, BoundingBoxSize, BoundingBox.center, CoppedImage);

	//Show images
	imshow("Original Image", GrayImage);
	imshow("Rotated Image", RotatedImage);
	imshow("Cropped Image", CoppedImage);
	waitKey(0);
}