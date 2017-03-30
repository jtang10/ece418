/*===
lab1-skeleton.cc

Abstract: Skeleton for Lab 1
===*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "image.h"
using namespace std;

int main (int argc, char* argv[])
{
	// check parameters' correctness
	if (argc != 3) 
	{
		cerr << "Usage: lab1 in.png out.png" << endl;
		return 1;
	}

	// load the image
	Image image;
	image.LoadPng (argv[1]);

	/*==

	Insert Lab 1 Code Here
	
	==*/
	
	// save it
	image.SavePng (argv[2]);
	
	return 0;
}
