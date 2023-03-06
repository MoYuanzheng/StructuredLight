#include "head.h"

int main() {
	std::vector<cv::Mat> GrayImage;
	std::vector<cv::Mat> PatternImage;
	Mat TruncatedPhaseImage;

	vector<string> gray_code = GrayCodeProjectCode(GrayBits);

	//! ¸ñÀ×Í¼
	GrayImage = GrayCodeProjectImage(gray_code);
	for (int i = 0; i < GrayImage.size(); i++) {
		cv::imshow("GrayImage_" + char(i), GrayImage[i]);
	}

	//! ¹âÕ¤Í¼
	PatternImage = generatePattern();
	for (int i = 0; i < PatternImage.size(); i++) {
		cv::imshow("PatternImage_" + char(i), PatternImage[i]);
		cv::waitKey(0);
	}

	//! ½Ø¶ÏÏàÎ»Í¼
	TruncatedPhaseImage = getTruncatedPhase();
	cv::imshow("TruncatedPhaseImage", TruncatedPhaseImage);
	cv::waitKey(0);

	return 0;
}
