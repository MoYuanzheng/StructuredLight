#include"head.h"

//! ������ͨ��ͼƬ��ֻ�ܽ���3��λ�ƣ���֤�� => ����
//Mat generatePattern(int n) {
//	// !����������դ����ͼ��
//	Mat Array_I = Mat::zeros(1140, 912, CV_8UC3);
//	std::vector<cv::Mat> channels;
//	cv::split(Array_I, channels);
//
//	double I_A = 127;
//	double I_B = 127;
//	const double PI = CV_PI;
//	for (int i = 0; i < channels[0].rows; i++) {
//		for (int j = 0; j < channels[0].cols; j++) {
//			// ! In(x,y)=A(x,y)+B(x,y)cos[��(x,y)+2*��(n-1)/3+��_0]
//			channels[0].at<uchar>(i, j) = I_A + I_B * cos((j % 18 * 20 + 0) * (2 * PI / 360));
//			channels[1].at<uchar>(i, j) = I_A + I_B * cos((j % 18 * 20 + 120) * (2 * PI / 360));
//			channels[2].at<uchar>(i, j) = I_A + I_B * cos((j % 18 * 20 + 240) * (2 * PI / 360));
//		}
//	}
//	cv::Mat mergeChannels[3] = { channels[0], channels[1], channels[2] };
//	cv::merge(mergeChannels, 3, Array_I);
//	//cv::imshow("TruncatedPhase", Array_I);
//	//cv::waitKey(0);
//	return Array_I;
//}


std::vector<cv::Mat> generatePattern() {
	// !���� n ����դ����ͼ��
	Mat temp = cv::Mat::zeros(progectRows, projectCols, 0);
	std::vector<cv::Mat> res;
	double I_A = 127;
	double I_B = 127;
	const double PI = CV_PI;

	for (int k = 0; k < phaseShiftSteps; k++) {
		res.push_back(temp.clone());
	}

	for (int i = 0; i < progectRows; i++) {
		for (int j = 0; j < projectCols; j++) {
			for (int k = 0; k < phaseShiftSteps; k++) {
				// ! In(x,y)=A(x,y)+B(x,y)cos[��(x,y)+2*��(n-1)/3+��_0]
				res[k].at<uchar>(i, j) = I_A + I_B * cos(((j % 18 * 20 + k * 120)) * (2 * PI / 360));
			}
		}
	}

	//cv::imshow("TruncatedPhase", Array_I);
	//cv::waitKey(0);
	return res;
}