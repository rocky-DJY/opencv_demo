#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include "census.h"
#include <vector>
using namespace std;
class dispart_estimate
{
public:
	dispart_estimate(cv::Mat left,cv::Mat right);
	void compute_disp(cv::Mat &census_left,cv::Mat &census_right);
	void cost_aggregation(); // ¾ÛºÏ
private:
	cv::Mat left, right;
	cv::Mat disp_image;
};

