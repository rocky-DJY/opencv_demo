#include "census.h"
#include "dispart_estimate.h"
#include <iostream>
// ZED includes
#include <sl/Camera.hpp>
// OpenCV includes
#include <opencv2/opencv.hpp>
using namespace sl;
using namespace std;
//  dsfdsfdksfdasjfdksjfdksjfdsjfds
cv::Mat slMat2cvMat(Mat& input);  // sl��opencv ����ת��
int main(int argc,char **argv) {
	// Create a ZED camera object
	Camera zed;
	// Set configuration parameters
	InitParameters init_params;
	init_params.camera_resolution = RESOLUTION::HD1080;
	init_params.depth_mode = DEPTH_MODE::ULTRA;
	init_params.coordinate_units = UNIT::MILLIMETER;
	//zed.setCameraSettings(VIDEO_SETTINGS::EXPOSURE, VIDEO_SETTINGS_VALUE_AUTO);

	//init_params.depth_maximum_distance = 1500;
	if (argc > 1) init_params.input.setFromSVOFile(argv[1]);
	// Open the camera
	ERROR_CODE err = zed.open(init_params);
	if (err != ERROR_CODE::SUCCESS) { // ��ʧ�����˳�
		printf("%s\n", toString(err).c_str());
		zed.close();
		return 1; // Quit if an error occurred
	}
	// zed open ֮��������ò���
	zed.setCameraSettings(VIDEO_SETTINGS::GAIN, 50);
	zed.setCameraSettings(VIDEO_SETTINGS::BRIGHTNESS, 4);
	zed.setCameraSettings(VIDEO_SETTINGS::EXPOSURE, 50);
	// Set runtime parameters after opening the camera
	RuntimeParameters runtime_parameters;
	runtime_parameters.sensing_mode = SENSING_MODE::STANDARD;
	
	// Prepare new image size to retrieve half-resolution images
	Resolution image_size = zed.getCameraInformation().camera_configuration.resolution;
	int new_width  = image_size.width / 3;
	int new_height = image_size.height / 3;
	Resolution new_image_size(new_width, new_height);
	// �������zedУ��ͼƬ  sl�ռ��opencv�ռ�
	Mat image_zed_undistort_left(new_width, new_height, MAT_TYPE::U8_C4);
	cv::Mat image_ocv_undistort_left = slMat2cvMat(image_zed_undistort_left);
	// �������zedУ��ͼƬ  sl�ռ��opencv�ռ�
	Mat image_zed_undistort_right(new_width, new_height, MAT_TYPE::U8_C4);
	cv::Mat image_ocv_undistort_right= slMat2cvMat(image_zed_undistort_right);

	char key = ' ';
	while (key != 'q') {
		if (zed.grab(runtime_parameters) == ERROR_CODE::SUCCESS) {
			// Retrieve the left image, depth image in half-resolution
			zed.retrieveImage(image_zed_undistort_left, VIEW::LEFT, MEM::CPU, new_image_size);
			zed.retrieveImage(image_zed_undistort_right, VIEW::RIGHT, MEM::CPU, new_image_size);
			//cout << point_cloud.getWidth() << "," << point_cloud.getHeight() << endl;
			// Display image and depth using cv:Mat which share sl:Mat data
			cv::imshow("Image_left", image_ocv_undistort_left);
			cv::imshow("Image_right", image_ocv_undistort_right);
			cvWaitKey(0);
			// new census obj ��Ҫ�ֶ��ͷŶ�����ڴ� 
			census *CT_obj_left  = new census(0);
			census *CT_obj_right = new census(1);
			int winsize_x = 5;
			int winsize_y = 5;
			cv::Mat census_image_left, census_image_right; // census �任��� ʹ��64F datatype
			CT_obj_left ->census_transform(image_ocv_undistort_left,  census_image_left, winsize_x,winsize_y);
			CT_obj_right->census_transform(image_ocv_undistort_right, census_image_right,winsize_x,winsize_y);

			//cv::imshow("census_transfrom_L", census_image_left);
			//cv::imshow("census_transfrom_R", census_image_right);
			// �ֶ��ͷ��ڴ�
			CT_obj_left ->~census();
			CT_obj_right->~census();

			// �Ӳ���� 
			dispart_estimate disp_obj(image_ocv_undistort_left,image_ocv_undistort_right);
			disp_obj.compute_disp(census_image_left, census_image_right);
		    cout<<"disp done"<<endl;
			// Handle key event
			key = cv::waitKey(10);

		}
	}
	zed.close();
	return 1;
}
cv::Mat slMat2cvMat(Mat& input) {
	// Mapping between MAT_TYPE and CV_TYPE
	int cv_type = -1;
	switch (input.getDataType()) {
	case MAT_TYPE::F32_C1: cv_type = CV_32FC1; break;
	case MAT_TYPE::F32_C2: cv_type = CV_32FC2; break;
	case MAT_TYPE::F32_C3: cv_type = CV_32FC3; break;
	case MAT_TYPE::F32_C4: cv_type = CV_32FC4; break;
	case MAT_TYPE::U8_C1: cv_type = CV_8UC1; break;
	case MAT_TYPE::U8_C2: cv_type = CV_8UC2; break;
	case MAT_TYPE::U8_C3: cv_type = CV_8UC3; break;
	case MAT_TYPE::U8_C4: cv_type = CV_8UC4; break;
	default: break;
	}
	// Since cv::Mat data requires a uchar* pointer, we get the uchar1 pointer from sl::Mat (getPtr<T>())
	// cv::Mat and sl::Mat will share a single memory structure
	return cv::Mat(input.getHeight(), input.getWidth(), cv_type, input.getPtr<sl::uchar1>(MEM::CPU));
}