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

//! 投影仪 高 - 宽 ，相移步数
const int progectRows = 1140;
const int projectCols = 1024;
const int phaseShiftSteps = 18;
//! 格雷码位数
const int GrayBits = 6;
const int phaseShiftPeriod = 16;
//! 相机 高 - 宽 
const int CCDRows = 1140;
const int CCDCols = 1024;

//! 投影仪与CCD光学中心距离
const int l_Op2Od = 20;
//! 投影仪、CCD光学中心与反射平面的距离
const int d_O2Plane = 100;

//! 截断相位的偏移角
const double theta_truncatedPhaseShifting = 9;

// !===投射阶段===
// !光栅条纹投影
std::vector<cv::Mat> generatePattern();

// !普通格雷码
std::vector<std::string> GrayCode(int n);
// !格雷码投影码
std::vector<std::string> GrayCodeProjectCode(int n);
// !投影格雷码图片
std::vector<cv::Mat> GrayCodeProjectImage(std::vector<string> grayCode);



// !===捕捉计算阶段===
// !
cv::Mat getPhaseLevelImage(std::vector<cv::Mat> grayImages, std::vector<cv::Mat> grayImagesMaxMin);
// !
int Gray2Decimal(int grayCode[GrayBits]);
// !CCD捕捉图像光栅图像并进行二值化处理
// --------------------------
// !计算截断相位
cv::Mat getTruncatedPhase();

// !解格雷码
// -------------------
// !计算各像素相位级次
// -------------------
// !解包裹 得到连续相位
Mat getContinuousPhase(Mat truncatedPhase, Mat phaseLevelImage);
//-----------------------------------
// !高度映射
Mat getHighlyMapped(Mat image);
//-----------------------------------

// !相机标定
//-----------------------------------
