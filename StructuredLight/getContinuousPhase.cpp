#include"head.h"

Mat getContinuousPhase(Mat truncatedPhase, Mat phaseLevelImage) {
	Mat continuePhase = Mat::zeros(CCDRows, CCDCols, CV_32FC1);

	for (int i = 0; i < CCDRows; i++) {
		for (int j = 0; j < CCDCols; j++) {
			continuePhase.at<float>(i, j) = truncatedPhase.at<float>(i, j) + 2 * CV_PI * phaseLevelImage.at<uchar>(i, j);
		}
	}

	return continuePhase;
}