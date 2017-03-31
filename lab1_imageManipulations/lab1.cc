/*===
lab1-skeleton.cc

Abstract: Skeleton for Lab 1
===*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "image.h"
using namespace std;

int getAverage(Image image, int row, int col) {
    int sum = 0;
    for (int i = row; i < row + 4; i++) {
        for (int j = col; j < col + 4; j++) {
            sum += image.Pixel(i, j);
        }
    }
    return sum / 16;
}

void setAverage(Image& image, int avg, int row, int col) {
    for (int i = row; i < row + 4; i++) {
        for (int j = col; j < col + 4; j++) {
            image.Pixel(i, j) = avg;
        }
    }
}

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
    for (int i = 0; i < image.Height(); i += 4) {
        for (int j = 0; j < image.Width(); j += 4) {
            int avg = getAverage(image, i, j);
            //cout << i << "\t" << j << "\t" << avg << endl;
            setAverage(image, avg, i, j);
        }
    }

    // save it
    image.SavePng (argv[2]);

    return 0;
}
