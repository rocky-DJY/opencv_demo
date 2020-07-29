#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/xfeatures2d/cuda.hpp>
#include <opencv2/cudafeatures2d.hpp>
using namespace std;
class census
{
public:
	census(int id);
	// census �任
	void census_transform(cv::Mat input_image, cv::Mat &modified_image, int window_sizex, int window_sizey);
	// �����������
	unsigned char census_hanming_dist(long long PL, long long PR);
	~census();
private:
	
};
class cost_sift {
public:
	cost_sift(int id);
	void sift_transform(const cv::Mat img0, const cv::Mat img1, 
		vector<float>& descriptor0, vector<float>& descriptor1);
	~cost_sift();
private:

};
