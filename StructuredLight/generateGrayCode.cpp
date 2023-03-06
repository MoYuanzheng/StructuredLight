#include "head.h"

std::vector<std::string> GrayCode(int n) {
	if (n < 1) {
		cout << "�����������������0" << endl;
		assert(0);
	}
	else if (n == 1) {
		std::vector<std::string> code;
		code.emplace_back("0");
		code.emplace_back("1");
		return code;
	}
	else {
		std::vector<std::string> code;
		std::vector<std::string> code_pre = GrayCode(n - 1);

		for (int idx = 0; idx < code_pre.size(); ++idx) {
			code.push_back("0" + code_pre[idx]);
		}
		for (int idx = int(code_pre.size() - 1); idx >= 0; --idx) {
			code.push_back("1" + code_pre[idx]);
		}
		return code;
	}
}

std::vector<std::string> GrayCodeProjectCode(int n) {

	std::vector<std::string> grayCode = { "01" };

	if (n < 1) {
		cout << "ͼ�������������0" << endl;
		assert(0);
	}
	else {
		for (int j = 2; j <= n; j++) {
			int number = pow(2, j) / 2;
			std::string units = {};
			for (int i = 0; i < number; i++) {
				if (i % 2 == 0) { units += "01"; }
				else { units += "10"; }
			}
			grayCode.push_back(units);
		}
	}
	return grayCode;
}

std::vector<cv::Mat> GrayCodeProjectImage(std::vector<std::string> grayCode) {
	std::vector<cv::Mat> grayImages;
	cv::Mat grayImage = cv::Mat::zeros(progectRows, projectCols, 0);
	for (int k = 0; k < grayCode.size(); k++) {
		int level = grayImage.cols / grayCode[k].length();

		for (int i = 0; i < grayImage.rows; i++) {
			for (int j = 0; j < grayImage.cols; j++) {
				int index = j / level;
				if (grayCode[k][index] == '0') {
					grayImage.at<uchar>(i, j) = 0;
				}
				else {
					grayImage.at<uchar>(i, j) = 255;
				}
			}
		}

		grayImages.push_back(grayImage.clone());

		//cv::imshow("grayImage", grayImage);
		//cv::waitKey(0);
	}

	return grayImages;
}