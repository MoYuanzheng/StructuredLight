#include"head.h"

//! �������������λ -> ���Ǻ����ۼӰ�
Mat getTruncatedPhase() {
	std::vector<cv::Mat> patternImage = generatePattern();

	Mat truncatedPhase = Mat::zeros(CCDRows, CCDCols, CV_32FC1);

	//! ��ֵ����Ϊ255��һ��
	double I_A = 127;

	for (int i = 0; i < CCDRows; i++) {
		for (int j = 0; j < CCDCols; j++) {
			double sinSum = 0, cosSum = 0;
			for (int k = 0; k < phaseShiftSteps; k++) {
				sinSum += patternImage[k].at<uchar>(i, j) * sin(2 * (k + 1) * CV_PI / phaseShiftSteps);
				cosSum += patternImage[k].at<uchar>(i, j) * cos(2 * (k + 1) * CV_PI / phaseShiftSteps);
			}
			//atan2ֵ��Ϊ(-PI,PI)
			double phase = -atan2(sinSum, cosSum);

			if (phase + theta_truncatedPhaseShifting / phaseShiftPeriod * CV_2PI >= CV_PI) {
				truncatedPhase.at<float>(i, j) = (phase + theta_truncatedPhaseShifting / phaseShiftPeriod * CV_2PI) - CV_2PI;
			}
			else {
				truncatedPhase.at<float>(i, j) = (phase + theta_truncatedPhaseShifting / phaseShiftPeriod * CV_2PI);
			}

		}
	}
	//int theta = CV_PI;
	//for (int i = 0; i < CCDRows; i++) {
	//	for (int j = 0; j < CCDCols; j++) {
	//		truncatedPhase.at<float>(i, j) = (truncatedPhase.at<float>(i, j) ) ;
	//	}
	//}

	//cv::imshow("truncatedPhase", truncatedPhase);
	//cv::waitKey(0);

	return truncatedPhase;
}