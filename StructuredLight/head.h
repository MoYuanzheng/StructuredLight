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

// !生成投影光栅条纹
//void generatePattern();
//Mat* generatePattern(int n);
Mat generatePattern(int n);
// !CCD得到截断相位
Mat getTruncatedPhase();
Mat getTruncatedPhase_Sum();

// !解包裹 得到连续相位
Mat getContinuousPhase(Mat& image);

// !高度映射
Mat getHighlyMapped(Mat& image);

vector<string> GrayCode(int n);

vector<string> GrayCodeProjectCode(int n);

std::vector<Mat> GrayCodeProjectImage(std::vector<string> grayCode);

