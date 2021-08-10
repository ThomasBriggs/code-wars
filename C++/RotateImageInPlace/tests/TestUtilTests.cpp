#include "TestUtil.h"
#include <gtest/gtest.h>

TEST(GenImage, 1x1)
{
    image img = {
    {1} };

    EXPECT_EQ(img, GenImg(1));
}

TEST(GenImage, 2x2)
{
    image img = {
    {1, 2},
    {3, 4} };

    EXPECT_EQ(img, GenImg(2));
}

TEST(GenImage, 3x3)
{
    image img = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9} };

    EXPECT_EQ(img, GenImg(3));
}

TEST(GenImage, 6x6)
{
    image img = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };

    EXPECT_EQ(img, GenImg(6));
}

TEST(GenRotatedImage, 1x1)
{
    image img = {
    {1} };

    EXPECT_EQ(img, GenImgRotated(1));
}

TEST(GenRotatedImage, 2x2)
{
    image img = {
    {3, 1},
    {4, 2} };

    EXPECT_EQ(img, GenImgRotated(2));
}

TEST(GenRotatedImage, 3x3)
{
    image img = {
    {7, 4, 1},
    {8, 5, 2},
    {9, 6, 3} };

    EXPECT_EQ(img, GenImgRotated(3));
}