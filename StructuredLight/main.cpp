#include "head.h"

int main() {
	std::vector<cv::Mat> image;
	//image = generatePattern(3);
	//Array_I = generatePattern(3);
	//cv::imshow("TruncatedPhase", Array_I[0]);
	//cv::imshow("TruncatedPhase1", Array_I[1]);
	//cv::imshow("TruncatedPhase2", Array_I[2]);
	//cv::waitKey(0);

	//image = getTruncatedPhase();


	int n = 4;
	vector<string> gray_code = GrayCodeProjectCode(n);
	cout << gray_code[1] << endl;
	image = GrayCodeProjectImage(gray_code);

	cv::imshow("grayImage", image[0]);
	cv::waitKey(0);
	return 0;
}