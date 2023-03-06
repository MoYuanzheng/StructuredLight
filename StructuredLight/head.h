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

// !����ͶӰ��դ����
//void generatePattern();
//Mat* generatePattern(int n);
Mat generatePattern(int n);
// !CCD�õ��ض���λ
Mat getTruncatedPhase();
Mat getTruncatedPhase_Sum();

// !����� �õ�������λ
Mat getContinuousPhase(Mat& image);

// !�߶�ӳ��
Mat getHighlyMapped(Mat& image);

vector<string> GrayCode(int n);

vector<string> GrayCodeProjectCode(int n);

std::vector<Mat> GrayCodeProjectImage(std::vector<string> grayCode);

