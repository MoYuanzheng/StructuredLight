#include "head.h"

int main() {
	Mat image = Mat::zeros(912, 1140, 0);
	//image = generatePattern(3);
	//Array_I = generatePattern(3);
	//cv::imshow("TruncatedPhase", Array_I[0]);
	//cv::imshow("TruncatedPhase1", Array_I[1]);
	//cv::imshow("TruncatedPhase2", Array_I[2]);
	//cv::waitKey(0);

	image = getTruncatedPhase();
}