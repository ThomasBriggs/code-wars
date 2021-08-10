#pragma once

#include <iostream>
#include <vector>
#include <array>

typedef std::vector<std::vector<int>> image;

void printArray(const image& img);
void rotateImage(image& img);