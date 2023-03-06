#include "head.h"

int main() {
	std::vector<cv::Mat> GrayImage;
	std::vector<cv::Mat> PatternImage;
	Mat TruncatedPhaseImage;

	vector<string> gray_code = GrayCodeProjectCode(GrayBits);

	//! ����ͼ
	GrayImage = GrayCodeProjectImage(gray_code);
	for (int i = 0; i < GrayImage.size(); i++) {
		cv::imshow("GrayImage_" + char(i), GrayImage[i]);
	}

	//! ��դͼ
	PatternImage = generatePattern();
	for (int i = 0; i < PatternImage.size(); i++) {
		cv::imshow("PatternImage_" + char(i), PatternImage[i]);
		cv::waitKey(0);
	}

	//! �ض���λͼ
	TruncatedPhaseImage = getTruncatedPhase();
	cv::imshow("TruncatedPhaseImage", TruncatedPhaseImage);
	cv::waitKey(0);

	return 0;
}
