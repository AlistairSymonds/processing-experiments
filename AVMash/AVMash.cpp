// AVMash.cpp : Defines the entry point for the console application.
//
// MrFilter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	/**
	* Image Import
	*/
	char* imageName = argv[1];

	Mat image;
	image = imread(imageName, 1);

	if (argc != 2 || !image.data)
	{
		printf("No image data \n ");
		waitKey(0);
		return -1;
	}


	/*
	* Processing
	*/

	auto seqStart = std::chrono::high_resolution_clock::now();
	
	Mat gray_image;
	cvtColor(image, gray_image, CV_BGR2GRAY);

	auto seqFinish = std::chrono::high_resolution_clock::now();
	std::cout << "Sequential processing took: " << std::chrono::duration_cast<std::chrono::milliseconds>(seqFinish - seqStart).count() << "ms\n";

	/*
	* Output
	*/
	imwrite("original.png", image);
	imwrite("gray.png", gray_image);
	waitKey(0);
	return 0;
}


