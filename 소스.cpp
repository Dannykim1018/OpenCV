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
Mat image;
bool pause = false;
double fpss;

Rect PatchRect;
Mat PatchImg;

unsigned int frame_index = 0;

static void onMouse(int event, int x, int y, int, void*)
{
	if (selectObject&pause)
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
		if (selectObject && pause)
		{
			if (selection.width > 5 && selection.height > 5)
			{
				PatchRect = selection;
				image(PatchRect).copyTo(PatchImg);
				imshow("Seclected Img", PatchImg);

				char str[100];
				sprintf_s(str, "%d,jpg", int(frame_index / fpss));
				imwrite(str, PatchImg);
			}
			selection = Rect(0, 0, 0, 0);
		}
		selectObject = false;
		pause = false;

		break;
	}
}

int main()
{
	
	printf("avi file name?");
	char nstr[255];
	scanf_s("%s", nstr);
	printf("-> %s", nstr);

	VideoCapture cap(nstr);
	Mat frame;
	namedWindow("Demo", 0);
	setMouseCallback("Demo",)


		return 0;
	}