#include "Functions.h"
#define MAX_INTENSITY_OF_A_COLOR_ 255
#define MIN_INTENSITY_OF_A_COLOR_ 0
#define WhitePixel_Vec3b Vec3b(MAX_INTENSITY_OF_A_COLOR_, MAX_INTENSITY_OF_A_COLOR_, MAX_INTENSITY_OF_A_COLOR_)
#define BlackPixel_Vec3b Vec3b(MIN_INTENSITY_OF_A_COLOR_, MIN_INTENSITY_OF_A_COLOR_, MIN_INTENSITY_OF_A_COLOR_)
int main()
{
	Mat img = imread("lena.png", IMREAD_COLOR);
	Mat grey(img.rows, img.cols, CV_8UC3);
	cvtColor(img, grey, COLOR_BGR2GRAY);

	vector<int> red(256);
	vector<int> green(256);
	vector<int> blue(256);
	vector<int> grey_v(256);

	vector<pair<int, int>> allBluep(256);
	vector<pair<int, int>> allGreenp(256);
	vector<pair<int, int>> allRedp(256);
	vector<pair<int, int>> allGreyp(256);

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			red   [img.at<Vec3b> (i, j)[2]] += 1;
			green [img.at<Vec3b> (i, j)[1]] += 1;
			blue  [img.at<Vec3b> (i, j)[0]] += 1;
			grey_v[grey.at<Vec3b>(i, j)[0]] += 1;
		}
	}

	Mat b_hist(100, 256, CV_8UC3, WhitePixel_Vec3b);
	Mat g_hist(100, 256, CV_8UC3, WhitePixel_Vec3b);
	Mat r_hist(100, 256, CV_8UC3, WhitePixel_Vec3b);
	Mat gr_hist(100, 256, CV_8UC3, WhitePixel_Vec3b);

	CreateVecForHist(red, r_hist, allRedp);
	CreateVecForHist(blue, b_hist, allBluep);
	CreateVecForHist(green, g_hist, allGreenp);
	CreateVecForHist(grey_v, gr_hist, allGreyp);

	for (int i = 0; i < allBluep.size() - 1; i++)
	{
		DrawLine(allBluep[i], allBluep[i + 1], 0, 0, 255, b_hist);
		DrawLine(allRedp[i], allRedp[i + 1], 255, 0, 0, r_hist);
		DrawLine(allGreenp[i], allGreenp[i + 1], 0, 255, 0, g_hist);
		DrawLine(allGreyp[i], allGreyp[i + 1], 255 / 2, 255 / 2, 255 / 2, gr_hist);
	}

	showImg("Img", img, 100, 100, img.cols, img.rows);
	showImg("BLUE_histogram", b_hist, 105 + img.cols, 100, b_hist.cols, b_hist.rows);
	showImg("RED_histogram", r_hist, 105 + img.cols, 135 + b_hist.rows, b_hist.cols, b_hist.rows);
	showImg("GREEN_histogram", g_hist, 105 + img.cols, 170 + b_hist.rows * 2, b_hist.cols, b_hist.rows);
	showImg("GREY_histogram", gr_hist, 105 + img.cols, 205 + b_hist.rows * 3, b_hist.cols, b_hist.rows);
	showImg("Grey_img", grey, 100, 135 + img.rows, grey.cols, grey.rows);

	waitKey();
	destroyAllWindows();
	return 0;
}
