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
        cerr << "Usage: diffImg output.png solution.png" << endl;
        return 1;
    }
    Image output;
    Image solution;
    output.LoadPng(argv[1]);
    solution.LoadPng(argv[2]);
    if (output.Width() != solution.Width() || output.Height() != solution.Height()) {
        cout << "Both images' dimension don\'t match" << endl;
    }
    else {
        for (int i = 0; i < output.Height(); i++) {
            for (int j = 0; j < output.Width(); j++) {
                if (output.Pixel(i, j) != solution.Pixel(i, j)) {
                    printf("Pixel(%d, %d) does\'t match\n", i, j);
                }
            }
        }
    }
    return 0;
}