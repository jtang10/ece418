/*===
lab2ab-skeleton.cc

Abstract: Skeleton for Lab 2 parts (a) and (b).
===*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "image.h"
#include "fft.h"
using namespace std;

int main (int argc, char* argv[])
{
	// check parameters' correctness
	if (argc != 3)
	{
		cerr << "Usage: " << argv[0] << " in.png out.png" << endl;
		return 1;
	}

	// load the image
	ComplexImage image;
	image.LoadPng (argv[1]);
	int width = image.Width();
	int height = image.Height();
	//Insert Lab 2 code here:

	//Compute the 2D FFT of the image
	vector<Complex> signal;
	signal.resize (width);

	for (int i = 0; i < height; ++i) {
		//copy each row into vector signal and perform FFT
		for (int j = 0; j < width; ++j) {
			signal[j] = image.Pixel(i, j);
		}
		FFT::Transform(signal);
		for (int j = 0; j < width; ++j) {
			image.Pixel(i, j) = signal[j];

		}
	}

	//Do above operations again along the columns
	for (int i = 0; i < width; ++i) {
		//copy each row into vector signal and perform FFT
		for (int j = 0; j < height; ++j) {
			signal[j] = image.Pixel(j, i);
		}
		FFT::Transform(signal);
		for (int j = 0; j < height; ++j) {
			image.Pixel(j, i) = signal[j];

		}
	}

	//Perform the frequency domain operations
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			image.Pixel(i, j) = abs(image.Pixel(i, j));
		}
	}

	//Take the inverse FFT to generate the picture
	for (int i = 0; i < height; ++i) {
		//copy each row into vector signal and perform FFT
		for (int j = 0; j < width; ++j) {
			signal[j] = image.Pixel(i, j);
		}
		FFT::InverseTransform(signal);
		for (int j = 0; j < width; ++j) {
			image.Pixel(i, j) = signal[j];

		}
	}

	//Do above operations again along the columns
	for (int i = 0; i < width; ++i) {
		//copy each row into vector signal and perform FFT
		for (int j = 0; j < height; ++j) {
			signal[j] = image.Pixel(j, i);
		}
		FFT::InverseTransform(signal);
		for (int j = 0; j < height; ++j) {
			image.Pixel(j, i) = signal[j];

		}
	}

	// save the image
	image.SavePng (argv[2]);

	return 0;
}
