#include "head.h"

int main() {

	//image = generatePattern(3);
	//Array_I = generatePattern(3);
	//cv::imshow("TruncatedPhase", Array_I[0]);
	//cv::imshow("TruncatedPhase1", Array_I[1]);
	//cv::imshow("TruncatedPhase2", Array_I[2]);
	//cv::waitKey(0);


	std::vector<cv::Mat> GrayImage;
	std::vector<cv::Mat> PatternImage;
	Mat TruncatedPhaseImage;

	vector<string> gray_code = GrayCodeProjectCode(GrayBits);

	//! ����ͼ
	GrayImage = GrayCodeProjectImage(gray_code);

	//! ��դͼ
	PatternImage = generatePattern();

	//! �ض���λͼ
	TruncatedPhaseImage = getTruncatedPhase();


	return 0;
}
