#include"head.h"

//! �������������λ -> ���Ǻ����ۼӰ�
Mat getTruncatedPhase() {
	std::vector<cv::Mat> patternImage = generatePattern();

	Mat I_phase = Mat::zeros(progectRows, projectCols, CV_32FC1);
	Mat I_phase_255 = Mat::zeros(progectRows, projectCols, 0);

	//! ��ֵ����Ϊ255��һ��
	double I_A = 127;

	for (int i = 0; i < progectRows; i++) {
		for (int j = 0; j < projectCols; j++) {
			double sinSum = 0, cosSum = 0;
			for (int k = 0; k < phaseShiftSteps; k++)
			{
				sinSum += patternImage[k].at<uchar>(i, j) * sin(2 * (k + 1) * CV_PI / phaseShiftSteps);
				cosSum += patternImage[k].at<uchar>(i, j) * cos(2 * (k + 1) * CV_PI / phaseShiftSteps);
			}
			double phase = -atan(sinSum / cosSum);

			I_phase.at<float>(i, j) = phase;
			I_phase_255.at<uchar>(i, j) = (phase + CV_PI / 2) / CV_PI * 255;
		}
	}


	//cv::imshow("TruncatedPhase_float", I_phase);
	//cv::imshow("TruncatedPhase_255", I_phase_255);

	//cv::waitKey(0);

	return I_phase_255;
}
/*
* �������Ʒ���ݹ�ʽ

	(sqrt(3) * (I[0].at<uchar>(i, j) - I[2].at<uchar>(i, j)))
	/
	(2 * I[1].at<uchar>(i, j) - I[0].at<uchar>(i, j) - I[2].at<uchar>(i, j))
*/