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



TEST(SwapData, Test)
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    std::array<int*, 4> pointerArr= {&a, &b, &c, &d};
    shiftArray(pointerArr);
    EXPECT_EQ(a, 4);
    EXPECT_EQ(b, 1);
    EXPECT_EQ(c, 2);
    EXPECT_EQ(d, 3);
}
