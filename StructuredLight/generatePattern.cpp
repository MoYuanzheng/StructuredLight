#include"head.h"

std::vector<cv::Mat> generatePattern() {
	// !生成 n 幅光栅条纹图像
	Mat temp = cv::Mat::zeros(progectRows, projectCols, 0);
	std::vector<cv::Mat> res;
	double I_A = 127;
	double I_B = 127;
	const double PI = CV_PI;

	for (int k = 0; k < phaseShiftSteps; k++) {
		res.push_back(temp.clone());
	}

	for (int k = 0; k < phaseShiftSteps; k++) {
		for (int i = 0; i < progectRows; i++) {
			for (int j = 0; j < projectCols; j++) {

				// ! In(x,y)=A(x,y)+B(x,y)cos[φ(x,y)+2*π(n-1)/N+Φ_0]
				res[k].at<uchar>(i, j) = I_A + I_B * cos((double(j % phaseShiftPeriod * 1000 / phaseShiftPeriod) * 2 * PI / 1000) + double(2 * PI * k * 1000 / phaseShiftSteps) / 1000);
			}
			//cout << I_B * cos(double(5 % phaseShiftPeriod / phaseShiftPeriod) * 2 * PI) + double(2 * PI * k / phaseShiftSteps) << endl;

		}
	}
	//cv::imshow("TruncatedPhase", Array_I);
	//cv::waitKey(0);
	return res;
}