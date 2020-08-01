#include "dispart_estimate.h"
#define MAX_DISPARITY 40
#define MIN_DISPARITY 20

dispart_estimate::dispart_estimate(cv::Mat left, cv::Mat right) {
	this->left  = left;
	this->right = right;
}
// computer the distance of the two vector
float dispart_estimate::dis_sift(const vector<float> Point_desc0, const vector<float> Point_desc1) {
    int len=Point_desc0.size();
    float diff;
    for(int i=0;i<len;i++) {
        diff += pow(Point_desc0[i] - Point_desc1[i], 2);
    }
    return pow(diff,0.5);
}
void dispart_estimate::compute_disp(cv::Mat &census_left, cv::Mat &census_right) {
	// �˺��������Ӳ�ͼ
	// ����  census_left��census_right�Ǿ���census�任��ͼƬ
	// ����census���� ���ۼ���,��ͼΪ��׼
	// census�������hanming������㺯�� 
	// sift ���� ʹ�ö����Աleft ��right ��������������
	// �ڴ��ۼ���ı�����  ͬʱ��Ȩsift�������ӵ�cost
	census cost_obj(0);
	// ����sift����   ���ۼ���
	cost_sift sift_obj(0);
	vector<vector<vector<float>>> desc0, desc1;
	sift_obj.sift_transform(left, right, desc0, desc1);
    // sift done
    cout<<"sift done"<<endl;
	vector<vector<vector<double>>> cost_res; // ��ά����  (W-MAX_DISPARITY)*H*D
 	for (int i = 0; i < left.rows; i++) {
		vector<vector<double>> cost_rows;    // ���浱ǰ�е����ص�� D���Ӳ��µĴ���
		for (int j = MAX_DISPARITY; j < left.cols; j++) {
			vector<double> cost_pix;         // ���浱ǰ���ص��D���Ӳ��µĴ���
			for (int m = MIN_DISPARITY; m <=MAX_DISPARITY; m++) {
				int current_right = j - m;
				// ���㲻ͬ�Ӳ��µ� sensus ����
				unsigned char census_hanming=cost_obj.census_hanming_dist(census_left.at<double>(i,j),census_right.at<double>(i,current_right));
				// the distance of the target points's vector
				float diff=dis_sift(desc0[i][j],desc1[i][current_right]);
				//cout<<diff<<", ";
				cost_pix.push_back(census_hanming+diff);
			}
			//cout<<endl;
			cost_rows.push_back(cost_pix);
		}
		cost_res.push_back(cost_rows);
	}
 	cout<<"cost size: "<<cost_res[0][0].size()<<endl;
	// ���۾ۺ�(ѡ�����ŵ��Ӳ�ֵ)
	// �Ӳ����
	// �Ż��Ӳ�
}
void dispart_estimate::cost_aggregation() {
	//
}