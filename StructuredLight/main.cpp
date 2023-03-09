#include "head.h"

int main() {

	std::vector<cv::Mat> GrayImage;
	std::vector<cv::Mat> PatternImage;
	Mat TruncatedPhaseImage;

	vector<string> gray_code = GrayCodeProjectCode(GrayBits);

	//! 格雷图
	GrayImage = GrayCodeProjectImage(gray_code);
	//for (int i = 0; i < GrayImage.size(); i++) {
	//	cv::imshow("GrayImage_" + char(i), GrayImage[i]);
	//}

	//! 光栅图
	PatternImage = generatePattern();
	for (int i = 0; i < PatternImage.size(); i++) {
		//cv::imshow("PatternImage", PatternImage[i]);
		cv::waitKey(0);
	}

	//! 截断相位图
	TruncatedPhaseImage = getTruncatedPhase();
	//cv::imshow("TruncatedPhaseImage", TruncatedPhaseImage);
	//cv::waitKey(0);

	//! 计算级次
	std::vector<cv::Mat> grayImagesMaxMin;
	cv::Mat grayImagesMin = cv::Mat::zeros(CCDRows, CCDCols, CV_8UC1);

	cv::Mat grayImagesMax(CCDRows, CCDCols, CV_8UC1, Scalar(255));

	grayImagesMaxMin.push_back(grayImagesMin);
	grayImagesMaxMin.push_back(grayImagesMax);

	cv::Mat phaseLevelImage = getPhaseLevelImage(GrayImage, grayImagesMaxMin);

	//！ 计算连续相位
	cv::Mat continuePhase = getContinuousPhase(TruncatedPhaseImage, phaseLevelImage);

	return 0;
}
