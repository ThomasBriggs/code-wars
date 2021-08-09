#include "ImageRotate.h"
#include <numeric>

image GenImg(size_t size)
{
    image output(size, std::vector<int>(size));
    int count = 1;
    for (auto &&i : output)
        for (auto &&j : i)
            j = count++; 
    return output;
}

image GenImgRotated(size_t size)
{
    image output(size, std::vector<int>(size));
    int count = 1;
    for (int i = size - 1; i >= 0; i--)
        for (size_t j = 0; j < size; j++)
            output[j][i] = count++;
    return output;   
}


