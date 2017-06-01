#include < opencv2\opencv.hpp>
#include < stdio.h>
#include <iostream>


#ifdef _DEBUG
#pragma comment(lib, "opencv_world320d.lib")
#else
#pragma comment(lib, "opencv_world320.lib")
#endif

using namespace std;
using namespace cv;


void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		printf("ILBUTTONDOWN down %d, %d \n", x, y);
		circle(*(Mat*)userdata, Point(x, y), 5, CV_RGB(255, 0, 0),  5);
	}
	else if (event == EVENT_RBUTTONDOWN)
	{
		printf("RBUTTONDOWN down %d, %d \n", x, y);
	}
	else if (event == EVENT_MBUTTONDOWN)
	{
		printf("MBUTTONDOWN down %d ,%d \n", x, y);
	}
	else if (event == EVENT_MOUSEMOVE)
	{
		printf("move %d, %d \n", x, y);
	}
	//imshow("img", *(Mat*)userdata);
}

int main()
{
	/*Mat img(500, 500, CV_8UC3);
	img.setTo(255);*/

	/*cv::Point pt(300, 300);
	line(img, Point(10, 10), pt, CV_RGB(255, 0, 0), 2);
	line(img, Point(300, 10), Point(30, 300), Scalar(255, 0, 0), 3);
*/
	/*circle(img, Point(250, 250), 100, CV_RGB(0, 255, 0), 3);
	cv::Point center(400, 400);
	circle(img, center, 300, Scalar(255, 255, 0), -1);
	circle(img, Point(40, 40), 10, Scalar(255, 0, 0), -1);*/

	/*rectangle(img, Rect(10, 10, 200, 200), CV_RGB(255, 0, 0), 2);
	rectangle(img, Rect(Point(40,40),Point(400,400)), Scalar(255, 0, 0), 10);
*/

	/*ellipse(img, Point(100, 100), Size(100, 50), 0, 0, 360, CV_RGB(255, 0, 0));
	ellipse(img, Point(100, 100), Size(100, 50), 30, 0, 360, CV_RGB(0, 255, 0));
	ellipse(img, Point(100, 100), Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));
	
	ellipse(img, Point(300, 300), Size(100, 50), 0, 0, 180, CV_RGB(255, 0, 0));
	ellipse(img, Point(300, 300), Size(100, 50), 30, 0, 270, CV_RGB(0, 255, 0));
	ellipse(img, Point(300, 300), Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));*/
	
	/*RotatedRect rRect = RotatedRect(Point2f(250, 250), Size2f(300, 100), 30);
	ellipse(img, rRect, CV_RGB(255, 0, 0),3);

	Point2f vertices[4];
	rRect.points(vertices);
	for (int i = 0; i < 4; i++)
	{
		line(img, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0));
	}
	
	Rect brect = rRect.boundingRect();
	rectangle(img, brect, Scalar(255, 0, 0));*/


	//vector<Point> contour;
	//contour.push_back(Point(50, 50));
	//contour.push_back(Point(300, 50));
	//contour.push_back(Point(350, 200));
	//contour.push_back(Point(300, 150));
	//contour.push_back(Point(150, 350));
	//contour.push_back(Point(100, 100));

	//const Point *pts = (const cv::Point*) Mat(contour).data;
	///*for (int k = 0; k < 6 ;k++)
	//{
	//	cout << pts[k] << endl;
	//}*/
	//int npts = Mat(contour).rows;


	///////*contour.clear();*/
	//vector<Point> contour2;
	//contour2.push_back(Point(230, 220));
	//contour2.push_back(Point(10, 50));
	//contour2.push_back(Point(50, 200));
	//contour2.push_back(Point(200, 150));

	//Point *pts2 = (cv::Point*) Mat(contour2).data;
	//int npts2 = Mat(contour2).rows;
	//
	//const Point *n_pts[2] = { pts, pts2 };
	//int n_npts[2] = { npts,npts2 };
	//polylines(img, n_pts, n_npts, 2, false, Scalar(255,0, 0),2);

	//// draw the polyline by line 
	//for (int i = 0; i < contour.size() - 1; ++i)
	//{
	//	line(img, contour[i],contour[i + 1], CV_RGB(255, 255, 0));
	//}
	//line(img, contour[contour.size() - 2], contour[contour.size() - 1], CV_RGB(255, 255, 0));

	//Convex poly
	/*cv::Point ptss[4];
	ptss[0] = cv::Point(100, 100);
	ptss[1] = cv::Point(150, 200);
	ptss[2] = cv::Point(300, 300);
	ptss[3] = cv::Point(400, 100);

	cv::fillConvexPoly(img, ptss, 4, cv::Scalar(0, 0, 200));*/


	//Mat img;
	//img = imread("gns.jpg");

	////textout example
	//char TestStr[100];
	//sprintf(TestStr, "total time : %lf sec", 0.001);

	//putText(img, TestStr, Point(10, 20), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1);

	/*namedWindow("show1", 0);
	namedWindow("threshord", 0);
	namedWindow("contours", 0);

	Mat img;
	img = imread("pattern.jpg");

	cvtColor(img, img, CV_RGB2GRAY);

	imshow("show1", img);

	threshold(img, img, 128, 255, CV_THRESH_BINARY);
	imshow("threshord", img);

	Mat dst = Mat::zeros(img.rows, img.cols, CV_8UC3);
	vector< vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(img.clone(), contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
*/
	/*drawContours(dst, contours, -1, CV_RGB(255, 0, 0), 1, 8, hierarchy);*/

	//// draw each connected component with its own random color
	////ex2
	//int idx = 0;
	//for (; idx >= 0; idx = hierarchy[idx][0])
	//{
	//	Scalar color(rand() & 255, rand() & 255, rand() & 255);
	//	drawContours(dst, contours, idx, color, 1, 8, hierarchy);
	//}
	//
	////ex3
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	for (int j = 0; j < contours[i].size() - 1; ++j)
	//	{
	//		line(dst, contours[i][j], contours[i][j + 1], CV_RGB(255, 0, 0), 1);
	//	}
	//	line(dst, contours[i][0], contours[i][contours[i].size() - 1], CV_RGB(255, 0, 0), 1);
	//}

	//for (int i = 0; i < contours.size(); i++)
	//	{
	//	Scalar color(rand() & 255, rand() & 255, rand() & 255);
	//	drawContours(dst, contours, i, color, 1, 8, hierarchy);
	//	}

	/*imshow("contours", dst);*/

	namedWindow("img", 0);
	Mat img = imread("gns.jpg");

	setMouseCallback("img", CallBackFunc, &img);

		while (1) {
			imshow("img", img);
			if(waitKey(20)>60)
				break;
		}
		destroyAllWindows();

	

		return 0;
	}