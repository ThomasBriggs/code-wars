#pragma once

#include <iostream>
#include <vector>
#include <array>

typedef std::vector<std::vector<int>> image;

void printArray(const image& img)
{
    for (auto&& i : img)
    {
        for (auto&& j : i)
            std::cout << j << ", ";
        std::cout << '\n';
    }
}

void shiftArray(std::array<int*, 4> data)
{
    for (size_t i = 1; i < 4; i++)
        std::swap(*data[0], *data[i]);
}

void rotateImageRec(image& img, int start, int last)
{
    std::array<int*, 4> swapData;
    for (size_t i = 0; i < img.size() - 1; i++)
    {
        swapData = {
            &img[start][i + start],
            &img[i + start][last - 1 - start],
            &img[last - 1][last - 1 - i - start],
            &img[last - 1 - i - start][start],
        };
        shiftArray(swapData);
    }
}

void rotateImage(image& img)
{
    for (size_t i = 0; i < img.size() / 2; i++)
        rotateImageRec(img, i, img.size() - i);
}