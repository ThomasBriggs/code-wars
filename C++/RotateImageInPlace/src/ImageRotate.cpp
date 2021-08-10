#include "ImageRotate.h"

void shiftArray(std::array<int*, 4> data);
void rotateLayer(image& img, int inset);

void shiftArray(std::array<int*, 4> data)
{
    for (size_t i = 1; i < 4; i++)
        std::swap(*data[0], *data[i]);
}

void rotateLayer(image& img, int inset)
{
    std::array<int*, 4> swapData;
    for (size_t i = inset; i < img.size() - 1 - inset; i++)
    {
        swapData = {
            &img[inset][i],
            &img[i][img.size() - 1 - inset],
            &img[img.size() - 1 - inset][img.size() - 1 - i],
            &img[img.size() - 1 - i][inset],
        };
        shiftArray(swapData);
    }
}

void rotateImage(image& img)
{
    for (size_t i = 0; i < img.size() / 2; i++)
        rotateLayer(img, i);
}

void printArray(const image& img)
{
    for (auto&& i : img)
    {
        for (auto&& j : i)
            std::cout << j << ", ";
        std::cout << '\n';
    }
}