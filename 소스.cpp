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
	

	namedWindow("img", 0);
	Mat img = imread("gns.jpg");

	setMouseCallback("img", CallBackFunc, &img);

		while (1) {
			imshow("img", img);
			if (waitKey(10) > 0)
			{
				break;
			}
		}
		destroyAllWindows();

		return 0;
	}