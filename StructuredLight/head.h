#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include<math.h>

using namespace std;
using namespace cv;

// !����ͶӰ��դ����
Mat generatePattern(Mat& image);

// !CCD�õ��ض���λ
Mat getTruncatedPhase(Mat& image);

// !����� �õ�������λ
Mat getContinuousPhase(Mat& image);

// !�߶�ӳ��
Mat getHighlyMapped(Mat& image);
