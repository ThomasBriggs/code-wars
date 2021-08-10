#include <gtest/gtest.h>
#include "ImageRotate.h"
#include "TestUtil.h"

TEST(RotateImage, 1x1)
{
    image img = GenImg(1);
    image rotated = GenImgRotated(1);
    rotateImage(img);
    EXPECT_EQ(img, rotated);
};

TEST(RotateImage, 2x2)
{
    image img = GenImg(2);
    image rotated = GenImgRotated(2);
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

TEST(RotateImage, 6x6)
{
    image img = GenImg(6);
    image rotated = GenImgRotated(6);
    rotateImage(img);
    EXPECT_EQ(img, rotated);
};

TEST(RotateImage, 100x100)
{
    image img = GenImg(100);
    image rotated = GenImgRotated(100);
    rotateImage(img);
    EXPECT_EQ(img, rotated);
}

TEST(RotateImage, 10000x10000)
{
    image img = GenImg(10000);
    image rotated = GenImgRotated(10000);
    rotateImage(img);
    EXPECT_EQ(img, rotated);
}
