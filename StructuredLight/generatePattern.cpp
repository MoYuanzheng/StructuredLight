#include"head.h"

/*
void generatePattern() {
	// !生成三幅光栅条纹图像
	Mat I_1 = Mat::zeros(912, 1140, 0);
	Mat I_2 = Mat::zeros(912, 1140, 0);
	Mat I_3 = Mat::zeros(912, 1140, 0);

	double I_A = 127;
	double I_B = 127;
	const double PI = CV_PI;
	for (int i = 0; i < I_1.rows; i++) {
		for (int j = 0; j < I_1.cols; j++) {
			// ! In(x,y)=A(x,y)+B(x,y)cos[φ(x,y)+2*π(n-1)/3+Φ_0]
			I_1.at<uchar>(i, j) = I_A + I_B * cos((j * 20 % 360 + 0) * (2 * PI / 360));
			I_2.at<uchar>(i, j) = I_A + I_B * cos((j * 20 % 360 + 60) * (2 * PI / 360));
			I_3.at<uchar>(i, j) = I_A + I_B * cos((j * 20 % 360 + 120) * (2 * PI / 360));
		}
	}

	cv::imshow("I_1", I_1);
	cv::imshow("I_2", I_2);
	cv::imshow("I_3", I_3);
	cv::waitKey(0);
}
*/
Mat generatePattern(int n) {
	// !生成三幅光栅条纹图像
	Mat Array_I = Mat::zeros(1140, 912, CV_8UC3);
	std::vector<cv::Mat> channels;
	cv::split(Array_I, channels);

	double I_A = 127;
	double I_B = 127;
	const double PI = CV_PI;
	for (int i = 0; i < channels[0].rows; i++) {
		for (int j = 0; j < channels[0].cols; j++) {
			// ! In(x,y)=A(x,y)+B(x,y)cos[φ(x,y)+2*π(n-1)/3+Φ_0]
			channels[0].at<uchar>(i, j) = I_A + I_B * cos((j * 20 % 360 + 0) * (2 * PI / 360));
			channels[1].at<uchar>(i, j) = I_A + I_B * cos((j * 20 % 360 + 120) * (2 * PI / 360));
			channels[2].at<uchar>(i, j) = I_A + I_B * cos((j * 20 % 360 + 240) * (2 * PI / 360));
		}
	}
	cv::Mat mergeChannels[3] = { channels[0], channels[1], channels[2] };
	cv::merge(mergeChannels, 3, Array_I);
	//cv::imshow("TruncatedPhase", Array_I);
	//cv::waitKey(0);
	return Array_I;
}