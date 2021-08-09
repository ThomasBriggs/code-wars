#pragma once

#include <iostream>
#include <vector>

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

void rotateImage(image& img)
{
    std::vector<int> savedRow;
}