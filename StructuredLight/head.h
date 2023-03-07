#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
using namespace cv;

//! ͶӰ�� �� - �� �����Ʋ���
const int progectRows = 1140;
const int projectCols = 912;
const int phaseShiftSteps = 3;
//! ������λ��
const int GrayBits = 4;

//! ��� �� - �� �����Ʋ���
const int CCDRows = 1140;
const int CCDCols = 912;

// !===Ͷ��׶�===
// !��դ����ͶӰ
std::vector<cv::Mat> generatePattern();

// !��ͨ������
std::vector<std::string> GrayCode(int n);
// !������ͶӰ��
std::vector<std::string> GrayCodeProjectCode(int n);
// !ͶӰ������ͼƬ
std::vector<cv::Mat> GrayCodeProjectImage(std::vector<string> grayCode);



// !===��׽����׶�===
// !
cv::Mat getPhaseLevelImage(std::vector<cv::Mat> grayImages, std::vector<cv::Mat> grayImagesMaxMin);
// !
int Gray2Decimal(int grayCode[GrayBits]);
// !CCD��׽ͼ���դͼ�񲢽��ж�ֵ������
// --------------------------
// !����ض���λ
cv::Mat getTruncatedPhase();

// !�������
// -------------------
// !�����������λ����
// -------------------
// !����� �õ�������λ
Mat getContinuousPhase(Mat image);
//-----------------------------------
// !�߶�ӳ��
Mat getHighlyMapped(Mat image);
//-----------------------------------

// !����궨
//-----------------------------------
