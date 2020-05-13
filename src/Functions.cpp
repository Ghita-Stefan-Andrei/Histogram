#include "Functions.h"
double f_max(vector<int> v)
{
	int max = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > max)
		{
			max = v[i];
		}
	}
	return max;
}

void DrawLine(pair<int, int> p0, pair<int, int>p1, int r, int g, int b, Mat& img)
{
	float m = 0.0f;
	if (p1.second != p0.second)
	{
		m = (float)(p1.first - p0.first) / (float)(p1.second - p0.second);
	}
	if (p1.second != p0.second && abs(m) <= 1.0f)
	{
		if (p0.second > p1.second)
		{
			swap(p0, p1);
		}
		float slope = (float)p0.first - m * (float)p0.second;
		for (int x = p0.second; x < p1.second; x++)
		{
			float y = m * (float)x + slope;
			img.at<Vec3b>((int)y, x)[0] = b;
			img.at<Vec3b>((int)y, x)[1] = g;
			img.at<Vec3b>((int)y, x)[2] = r;
		}
	}
	else
	{
		if (p0.first > p1.first)
		{
			swap(p0, p1);
		}
		float w = (float)(p1.second - p0.second) / (float)(p1.first - p0.first);
		float p = (float)p0.second - w * (float)p0.first;
		for (int y = p0.first; y < p1.first; y++)
		{
			float x = w * (float)y + p;
			img.at<Vec3b>(y, (int)x)[0] = b;
			img.at<Vec3b>(y, (int)x)[1] = g;
			img.at<Vec3b>(y, (int)x)[2] = r;
		}
	}
}

void CreateVecForHist(vector<int> color, Mat hist, vector<pair<int, int>>& vec)
{
	double scaleto_100 = 100 / f_max(color);
	for (int j = 0; j < color.size(); j++)
	{
		double scaledValue = scaleto_100 * color[j];
		pair<int, int> point;
		point.first = hist.rows - 1 - scaledValue;
		point.second = j;
		vec[j] = point;
	}
}

void showImg(string name, Mat img, int pozX, int pozY,int length,int height)
{
	namedWindow(name, WINDOW_FREERATIO);
	imshow(name, img);
	resizeWindow(name, length, height);
	moveWindow(name, pozX, pozY);
}