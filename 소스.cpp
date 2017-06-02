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

//instances
bool selectObject = false;
Rect selection;
Point origin; 
int trackObject = 0;
Mat image;

static void onMouse(int event, int x, int y, int, void*)
{
	if (selectObject)
	{
		selection.x = MIN(x, origin.x);
		selection.y = MIN(y, origin.y);
		selection.width = std::abs(x - origin.x);
		selection.height = std::abs(y - origin.y);

		selection &= Rect(0, 0, image.cols, image.rows);

	}

	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		origin = Point(x, y);
		selection = Rect(x, y, 0, 0);
		selectObject = true;
		break;

	case CV_EVENT_LBUTTONUP:
		selectObject = false;
		if (selection.width > 0 && selection.height > 0)
			trackObject = -1;
		break;
	}

}

int main(void)
{
	VideoCapture cap(0);
	Mat frame;
	namedWindow("Demo", 0);
	setMouseCallback("Demo", onMouse, 0);

	for (;;)
	{

		cap >> frame;
		if (frame.empty())
			break;

		frame.copyTo(image);

		if (selectObject && selection.width > 0 && selection.height > 0)
		{
			Mat roi(image, selection);
			bitwise_not(roi, roi);

			printf("%d %d %d %d\n", selection.x, selection.y, selection.width, selection.height);

		}
		imshow("Demo", image);

		if (waitKey(10) == 27)
			break;
		/*char key = -1;
		char ch = waitKey(10);
		if (ch != -1) key = ch;
		if (key == 27) break;*/
	}

	return 0;

}