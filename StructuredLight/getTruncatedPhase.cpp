#include"head.h"

Mat getTruncatedPhase(Mat& image) {
	image = imread("D:\\image/book/DIP3E_Original_Images_CH06/Fig0638(a)(lenna_RGB).tif");

	std::vector<cv::Mat> channels;
	cv::split(image, channels);

	cv::imshow("BGR", image);
	cv::imshow("B", channels[0]);
	cv::imshow("G", channels[1]);
	cv::imshow("R", channels[2]);

	Mat blurImageB, blurImageG, blurImageR;
	cv::blur(channels[0], blurImageB, Size(5, 5));
	cv::blur(channels[1], blurImageG, Size(5, 5));
	cv::blur(channels[2], blurImageR, Size(5, 5));

	cv::imshow("blurImageB", blurImageB);
	cv::imshow("blurImageG", blurImageG);
	cv::imshow("blurImageR", blurImageR);

	cv::Mat mergeChannels[3] = { blurImageB, blurImageG, blurImageR };
	cv::merge(mergeChannels, 3, image);
	cv::imshow("MergeRGB", image);

	cv::waitKey(0);
	return image;
}