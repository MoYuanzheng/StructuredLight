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

/*
	����������
	������
		int n��������λ��
	����ֵ��
		std::vector<std::string> grayCode��string�͵�Vector һϵ�и�����
*/
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

/*
	����������ͶӰͼƬ
	������
		std::vector<std::string> grayCode��String�͵�Vector
	����ֵ��
		std::vector<cv::Mat> grayImages��Mat�͵�Vector һϵ�и�����ͼƬ
*/
std::vector<cv::Mat> GrayCodeProjectImage(std::vector<std::string> grayCode) {
	std::vector<cv::Mat> grayImages;
	cv::Mat grayImage = cv::Mat::zeros(progectRows, projectCols, CV_8UC1);
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

/*
	����������
	������
		std::vector<cv::Mat> grayImages��Mat�͵�Vector ������ɼ���һϵ�и�����ͼƬ
	����ֵ��
		cv::Mat phaseLevelImages��Mat�͵�Vector ��λ����ͼ
	ע��㣺
		���ڽض���λ��ƫ�ư�����ڣ��ʼ���ͼӦ���򲹳�������
*/
cv::Mat getPhaseLevelImage(std::vector<cv::Mat> grayImages, std::vector<cv::Mat> grayImagesMaxMin) {
	cv::Mat phaseLevelImage = cv::Mat::zeros(CCDRows, CCDCols, CV_8UC1);

	for (int i = 0; i < CCDRows; i++) {
		for (int j = 0; j < CCDCols; j++) {
			int tempCode[GrayBits]{};;
			for (int k = 0; k < grayImages.size(); k++) {
				// !��ֵ�������� 
				double I_threshold =
					(grayImages[k].at<uchar>(i, j) - grayImagesMaxMin[0].at<uchar>(i, j))
					/ (grayImagesMaxMin[1].at<uchar>(i, j) - grayImagesMaxMin[0].at<uchar>(i, j));

				if (I_threshold >= 0.5) { tempCode[k] = 1; }
				else { tempCode[k] = 0; }

			}
			//��ֵ
			int num = Gray2Decimal(tempCode);

			phaseLevelImage.at<uchar>(i, j) = num;
		}
	}
	//cv::imshow("phaseLevelImage", phaseLevelImage);
	//cv::waitKey(0);
	return phaseLevelImage;
}

/*
	������תʮ����
	������
		String Code���ɸ���������ַ���
	����ֵ��
		int num��������תΪʮ���Ƶ�ֵ
*/
int Gray2Decimal(int arrayGrayCode[GrayBits]) {
	int num = 0;
	int binCode[GrayBits]{};
	binCode[0] = arrayGrayCode[0];

	//! ������ת������
	for (int i = 1; i < GrayBits; i++) {
		if (arrayGrayCode[i] + binCode[i - 1] == 2) { binCode[i] = 0; }
		else { binCode[i] = arrayGrayCode[i] + binCode[i - 1]; }
	}

	//! ������תʮ����
	for (int i = GrayBits - 1; i >= 0; i--) {
		if (binCode[i] == 1) {
			num += pow(2, GrayBits - i - 1);
		}
	}
	//cout << num << endl;
	return num;
}