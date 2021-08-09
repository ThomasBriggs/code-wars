#include <gtest/gtest.h>
#include "ImageRotate.h"
#include "TestUtil.h"

TEST(GenImage, 1x1)
{
    image img = {
    {1} };

    EXPECT_EQ(img, GenImg(1));
}

TEST(GenImage, 3x3)
{
    image img = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9} };

    EXPECT_EQ(img, GenImg(3));
}

TEST(GenRotatedImage, 1x1)
{
    image img = {
    {1} };

    EXPECT_EQ(img, GenImgRotated(1));
}

TEST(GenRotatedImage, 3x3)
{
    image img = {
    {7, 4, 1},
    {8, 5, 2},
    {9, 6, 3} };

    EXPECT_EQ(img, GenImgRotated(3));
}

TEST(RotateImage, 1x1)
{
    image img = GenImg(1);
    image rotated = GenImgRotated(1);
    rotateImage(img);
    EXPECT_EQ(img, rotated);
};


TEST(RotateImage, 3x3)
{
    image img = GenImg(3);
    image rotated = GenImgRotated(3);
    rotateImage(img);
    EXPECT_EQ(img, rotated);
};

TEST(RotateImage, 5x5)
{
    image img = GenImg(5);
    image rotated = GenImgRotated(5);
    rotateImage(img);
    EXPECT_EQ(img, rotated);
};
