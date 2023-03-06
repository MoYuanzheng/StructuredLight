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
const int projectCols = 912;
const int phaseShiftSteps = 3;

// !生成投影光栅条纹
std::vector<cv::Mat> generatePattern();


// !CCD得到截断相位
cv::Mat getTruncatedPhase();

// !解包裹 得到连续相位
Mat getContinuousPhase(Mat& image);

// !高度映射
Mat getHighlyMapped(Mat& image);

// !格雷码相关
// !普通格雷码
std::vector<std::string> GrayCode(int n);
// !格雷码投影码
std::vector<std::string> GrayCodeProjectCode(int n);
// !投影格雷码图片
std::vector<cv::Mat> GrayCodeProjectImage(std::vector<string> grayCode);

