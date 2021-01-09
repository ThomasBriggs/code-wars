#include <iostream>

int beeramid(int bonus, double price)
{
    if (bonus <= 0) return 0;
    int canAmnt = bonus / price;
    int height = 1;
    while (canAmnt >= 0) {
        canAmnt -= height * height;
        height ++;
    }
    return height - 2;
}

int main(int argc, char const *argv[])
{
    std::cout << beeramid(10, 2) << std::endl;
    return 0;
}
