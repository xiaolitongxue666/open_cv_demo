/* File: extract_tables.cpp */
/* Author: xiaoli*/
/* Date: Sun May 17 15:59:19 CST 2020 */

#include "show_img.h"
#include "extract_tables.h"

int ExtractTables(Mat OriginalImage)
{
    //Convert to gray image
    Mat GrayImage;
    cvtColor(OriginalImage, GrayImage, COLOR_BGR2GRAY);
    ShowImage(GrayImage, "Gray image");

    //Adapt threshold
    Mat BlackBackGroundImage;
    adaptiveThreshold(~GrayImage, BlackBackGroundImage, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
    ShowImage(BlackBackGroundImage, "Black background image");

    //Get horizontal and vertical lines
    Mat HorizontalImage = BlackBackGroundImage.clone();
    Mat VerticalImage = BlackBackGroundImage.clone();

    //Specify size on horizontal axis
    int Scale = 20;//This variable in order to increase/decrease the amount of lines to be detected
    int HorizontalSize = HorizontalImage.cols / Scale;

    //Create structure element for extracting horizontal lines through morphology operations
    Mat HorizontalStructure = getStructuringElement(MORPH_RECT, Size(HorizontalSize, 1));

    //Apply morphology operations
    erode(HorizontalImage, HorizontalImage, HorizontalStructure, Point(-1, -1));
    dilate(HorizontalImage, HorizontalImage, HorizontalStructure, Point(-1, -1));
    ShowImage(HorizontalImage, "All horizontal lines");

    //Vertical lines
    int VerticalSize = VerticalImage.rows / Scale;
    Mat VerticalStructure = getStructuringElement(MORPH_RECT, Size(1, VerticalSize));
    erode(VerticalImage, VerticalImage, VerticalStructure, Point(-1, -1));
    dilate(VerticalImage, VerticalImage, VerticalStructure, Point(-1, -1));
    imshow("VerticalImage", VerticalImage);

    //Create a Mask cross by all lines of tables
    Mat Mask = HorizontalImage + VerticalImage;
    ShowImage(Mask, "Only show tables");

    /*Find the IntersectionPoints between the lines of the tables,
     * we will use this information in order to discriminate tables from pictures
     * (tables will contain more than 4 IntersectionPoints while a picture only 4 (i.e. at the corners))*/
    Mat IntersectionPoints;
    bitwise_and(HorizontalImage, VerticalImage, IntersectionPoints);
    ShowImage(IntersectionPoints, "Intersection points");

    vector<Vec4i> Hierarchy;
    vector<vector<Point> > Contours;

    cv::findContours(Mask, Contours, Hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));

    vector<vector<Point> > ContoursPoly(Contours.size());
    vector<Rect> BoundRect(Contours.size());
    vector<Mat> Rios;

    //Find external contours from the mask, which most probably will belong to tables or to images
    for (size_t i = 0; i < Contours.size(); i++)
    {
        //Find the area of each contour
        double Area = contourArea(Contours[i]);
        //Filter individual lines of blobs that might exist and they do not represent a table
        if (Area < 100)
            continue;

        approxPolyDP(Mat(Contours[i]), ContoursPoly[i], 3, true);
        BoundRect[i] = boundingRect(Mat(ContoursPoly[i]));

        //Find the number of intersection points that each table has
        Mat Roi = IntersectionPoints(BoundRect[i]);

        vector<vector<Point> > IntersectionPointsContours;
        findContours(Roi, IntersectionPointsContours, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

        //If the number is not more than 5 then most likely it not a table
        if (IntersectionPointsContours.size() <= 4)
            continue;

        //Save this area
        Rios.push_back(OriginalImage(BoundRect[i]).clone());
        //Draw a rectangle on original image
        rectangle(OriginalImage, BoundRect[i].tl(), BoundRect[i].br(), Scalar(0, 255, 0), 1, 8, 0);
    }

    //Control all area
    for (size_t i = 0; i < Rios.size(); ++i)
    {
        //Temp save files
        //stringstream ss;
        //ss << "Roi" << i << "";
        ShowImage(Rios[i], "Rio");
        waitKey();
    }
    ShowImage(OriginalImage, "Contours");

    return 0;
}
