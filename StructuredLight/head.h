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
const int projectCols = 1024;
const int phaseShiftSteps = 18;
//! ������λ��
const int GrayBits = 6;
const int phaseShiftPeriod = 16;
//! ��� �� - �� 
const int CCDRows = 1140;
const int CCDCols = 1024;

//! ͶӰ����CCD��ѧ���ľ���
const int l_Op2Od = 20;
//! ͶӰ�ǡ�CCD��ѧ�����뷴��ƽ��ľ���
const int d_O2Plane = 100;

//! �ض���λ��ƫ�ƽ�
const double theta_truncatedPhaseShifting = 9;

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
Mat getContinuousPhase(Mat truncatedPhase, Mat phaseLevelImage);
//-----------------------------------
// !�߶�ӳ��
Mat getHighlyMapped(Mat image);
//-----------------------------------

// !����궨
//-----------------------------------
