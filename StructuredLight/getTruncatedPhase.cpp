#include"head.h"

//! ��ֵ������
Mat getTruncatedPhase() {
	//! ���ڷ�������ͼƬ �ʽ�������ͨ��ͼƬ ���㴫ֵ
	Mat image = generatePattern(3);
	std::vector<cv::Mat> I;
	cv::split(image, I);
	cv::imshow("TruncatedPhase", I[0]);
	cv::imshow("TruncatedPhase", I[1]);
	cv::imshow("TruncatedPhase", I[2]);


	Mat I_phase = Mat::zeros(1140, 912, CV_32FC1);
	Mat I_phase_255 = Mat::zeros(1140, 912, 0);
	cv::imshow("TruncatedPhase-I[0]", I[0]);

	//! ��ֵ����Ϊ255��һ��
	double I_A = 127;

	for (int i = 0; i < I_phase.rows; i++) {
		for (int j = 0; j < I_phase.cols; j++) {
			double phase = atan(
				(sqrt(3) * (I[0].at<uchar>(i, j) - I[2].at<uchar>(i, j)))
				/
				(2 * I[1].at<uchar>(i, j) - I[0].at<uchar>(i, j) - I[2].at<uchar>(i, j))
			);
			I_phase.at<float>(i, j) = phase;
			I_phase_255.at<uchar>(i, j) = (phase + CV_PI / 2) / CV_PI * 255;
		}
	}


	cv::imshow("TruncatedPhase_float", I_phase);
	cv::imshow("TruncatedPhase_255", I_phase_255);

	cv::waitKey(0);

	return I_phase;
}

//! ���Һ����ۼӰ� N = 3
Mat getTruncatedPhase_Sum() {
	int N = 3;
	//! ���ڷ�������ͼƬ �ʽ�������ͨ��ͼƬ ���㴫ֵ
	Mat image = generatePattern(3);
	std::vector<cv::Mat> I;
	cv::split(image, I);
	cv::imshow("TruncatedPhase", I[0]);
	cv::imshow("TruncatedPhase", I[1]);
	cv::imshow("TruncatedPhase", I[2]);


	Mat I_phase = Mat::zeros(1140, 912, CV_32FC1);
	Mat I_phase_255 = Mat::zeros(1140, 912, 0);
	cv::imshow("TruncatedPhase-I[0]", I[0]);

	//! ��ֵ����Ϊ255��һ��
	double I_A = 127;

	for (int i = 0; i < I_phase.rows; i++) {
		for (int j = 0; j < I_phase.cols; j++) {
			double phase = atan(
				(I[0].at<uchar>(i, j) * sin(2 * 1 * CV_PI / N) + I[1].at<uchar>(i, j) * sin(2 * 2 * CV_PI / N) + I[2].at<uchar>(i, j) * sin(2 * 3 * CV_PI / N))
				/
				(I[0].at<uchar>(i, j) * cos(2 * 1 * CV_PI / N) + I[1].at<uchar>(i, j) * cos(2 * 2 * CV_PI / N) + I[2].at<uchar>(i, j) * cos(2 * 3 * CV_PI / N))
			);
			I_phase.at<float>(i, j) = phase;
			I_phase_255.at<uchar>(i, j) = (phase + CV_PI / 2) / CV_PI * 255;
		}
	}


	cv::imshow("TruncatedPhase_float", I_phase);
	cv::imshow("TruncatedPhase_255", I_phase_255);

	cv::waitKey(0);

	return I_phase;
}