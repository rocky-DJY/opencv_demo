#include "census.h"
census::census(int id) {
	//cout << "creat_census_id: "<<id << endl;
}
census::~census() {
	//cout << "delete census_obj" << endl;
}
void census::census_transform(cv::Mat input_image, cv::Mat &modified_image, int window_sizex, int window_sizey) {
		int image_height = input_image.rows;
		int image_width = input_image.cols;
		modified_image = cv::Mat::zeros(image_height, image_width, CV_64F);
		//-----------census�任  ---------------------------------
		int offsetx = (window_sizex - 1) / 2;
		int offsety = (window_sizey - 1) / 2;
		for (int j = 0; j < image_width - window_sizex; j++)
		{
			for (int i = 0; i < image_height - window_sizey; i++)
			{
				unsigned long census = 0;
				uchar current_pixel = input_image.at<uchar>(i + offsety, j + offsetx); //������������
				cv::Rect roi(j, i, window_sizex, window_sizey); //���δ���
				cv::Mat window(input_image, roi);

				for (int a = 0; a < window_sizey; a++)
				{
					for (int b = 0; b < window_sizex; b++)
					{
						if (!(a == offsety && b == offsetx))//�������ز����ж�
						{
							census = census << 1;           //����1λ
						}
						uchar temp_value = window.at<uchar>(a, b);
						if (temp_value <= current_pixel)    //��ǰ����С���������� 01
						{
							census += 1;
						}
					}
				}
				modified_image.at<double>(i + offsety, j + offsetx) = census;
			}
		}
}
unsigned char census::census_hanming_dist(long long PL, long long PR) {
	// Fast Hamming distance algorithm
	// number ����0  ����ͬ����census���л���ת���Ĵ���
	unsigned char number = 0;
	long long v;
	v = PL ^ PR;            /* ^ ������� ��ͬΪ1 ��ͬΪ0*/
	while (v)
	{
		v &= (v - 1);            /* & ������*/
		number++;
	}
	return number;
}
cost_sift::cost_sift(int id) {

}
cost_sift::~cost_sift() {
	//delete the class's variable member
}
void cost_sift::sift_transform(const cv::Mat img0,const cv::Mat img1,
							   vector<float>& descriptor0,vector<float>& descriptor1) 
{
	cv::cuda::GpuMat left_img;
	cv::cuda::GpuMat right_img;
	cv::Mat img0_gray, img1_gray;
	cvtColor(img0, img0_gray, CV_BGR2GRAY);
	cvtColor(img1, img1_gray, CV_BGR2GRAY);
	left_img.upload(img0_gray);
	right_img.upload(img1_gray);

	//�������������ԭ���ǣ�
	//explicit SURF_CUDA(
	//double _hessianThreshold,    //SURF��ɭ��������ֵ ԽС����������Խ��
	//int _nOctaves=4,             //�߶Ƚ���������
	//int _nOctaveLayers=2,		   //ÿһ���߶Ƚ���������
	//bool _extended=false,		   //���true��ô�õ�����������128ά��������64ά
	//float _keypointsRatio=0.01f,
	//bool _upright = false
	//);
	//Ҫ����⼸�������漰SURF��ԭ��
	int dim = 64;
	cv::cuda::SURF_CUDA surf(50, 4, 3);
	/*�������漸��GpuMat�洢keypoint����Ӧ��descriptor*/
	vector<cv::KeyPoint> key0(img0.rows*img0.cols);
	vector<cv::KeyPoint> key1(img0.rows*img0.cols);
	vector<cv::KeyPoint> key_demo;
	cv::cuda::GpuMat keypt0, keypt1;
	cv::cuda::GpuMat desc0,  desc1;
	int point = 0;
	// �Զ���������  ��ÿ�����ص�  ƽ�л��б�����ʽ ���������ӵ������Դ�������
	for (int i = 0; i < img0.rows; i++)
		for (int j = 0; j < img0.cols; j++) {
			key0[point].pt.x = j;
			key0[point].pt.y = i;
			key0[point].size = 30;
			key0[point].octave = 0;
			key1[point].pt.x = j;
			key1[point].pt.y = i;
			key1[point].size = 30;
			key1[point].octave = 0;
			point++;
		}
	surf.uploadKeypoints(key0, keypt0);
	surf.uploadKeypoints(key1, keypt1);
	//keypt0.upload(key0);
	//keypt1.upload(key1);
	//����������   gpu_mat (i,j)=(w,h)����ͨmat�෴
	surf(left_img,  cv::cuda::GpuMat(), keypt0, desc0,true); //ʹ���Զ����keypt
	surf(right_img, cv::cuda::GpuMat(), keypt1, desc1,true); 
	surf.downloadDescriptors(desc0, descriptor0);  // ���������Ӹ�vector
	surf.downloadDescriptors(desc1, descriptor1);
	// cout << keypt0.size() << endl;
	// ��64ά��������w*h�ķֲ�����
	int index = 0;
	vector<vector<vector<float>>> desc0_wh;   // w*h�ֲ��ĵ������
	vector<vector<vector<float>>> desc1_wh;   // w*h�ֲ��ĵ������
	for (int i = 0; i < img0_gray.rows; i++) { 
		vector<vector<float>> desc0_point_row;  // ÿһ�е�ÿһ���������
		vector<vector<float>> desc1_point_row;
		for (int j = 0; j < img0_gray.cols; j++) {
			vector<float> desc0_point;          // ÿ64��Ϊһ���������
			vector<float> desc1_point;
			for (int m = 0; m <dim ; m++) {
				desc0_point.push_back(descriptor0[index]);
				desc1_point.push_back(descriptor0[index]);
				index++;
			}
			desc0_point_row.push_back(desc0_point);
			desc1_point_row.push_back(desc1_point);
		}
		desc0_wh.push_back(desc0_point_row);
		desc1_wh.push_back(desc1_point_row);
	}
	//cout << keypt0.size().width << endl;
	//cout << desc0.size().width << endl;
	cout << "descriptor generate" << endl;
}