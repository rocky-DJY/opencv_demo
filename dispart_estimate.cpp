#include "dispart_estimate.h"
#define MAX_DISPARITY 60    // 60
#define MIN_DISPARITY 3

dispart_estimate::dispart_estimate(cv::Mat left, cv::Mat right) {
	this->left  = left;
	this->right = right;
}
void dispart_estimate::compute_disp(cv::Mat &census_left, cv::Mat &census_right) {
	// 此函数计算视差图
	// 输入  census_left，census_right是经过census变换的图片
	// 创建census对象 代价计算,左图为基准
	// census对象调用hanming距离计算函数 
	// sift 对象 使用对象成员left 和right 计算特征描述子
	// 在代价计算的遍历中  同时加权sift的描述子的cost
	census cost_obj(0);
	// 创建sift对象   代价计算
	cost_sift sift_obj(0);
	vector<float> desc0, desc1;
	sift_obj.sift_transform(left, right, desc0, desc1);

	vector<vector<vector<double>>> cost_res; // 三维矩阵  (W-MAX_DISPARITY)*H*D
 	for (int i = 0; i < left.rows; i++) {
		vector<vector<double>> cost_rows;    // 缓存当前行的像素点的 D个视差下的代价
		for (int j = MAX_DISPARITY; j < left.cols; j++) {
			vector<double> cost_pix;         // 缓存当前像素点的D个视差下的代价
			for (int m = MIN_DISPARITY; m <=MAX_DISPARITY; m++) {
				int current_right = j - m;
				//计算不同视差下的 sensus 距离
				unsigned char census_hanming=cost_obj.census_hanming_dist(
					census_left.at<double>(i,j),
					census_right.at<double>(i,current_right));
				cost_pix.push_back(census_hanming);
			}
			cost_rows.push_back(cost_pix);
		}
		cost_res.push_back(cost_rows);
	}
	// 代价聚合(选出最优的视差值)
	// 视差计算
	// 优化视差
}
void dispart_estimate::cost_aggregation() {
	
}