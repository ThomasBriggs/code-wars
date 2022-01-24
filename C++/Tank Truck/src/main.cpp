#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

class VolTank
{
public:
    static int tankVol(int h, int d, int vt)
    {
        auto r = d * 0.5;
        auto theta = std::acos((r-h)/r)*2;
        auto AoSec = ((theta*(180/M_PI))/360) * M_PI * r * r;
        auto AoT = 0.5 * r * r * (std::sin(theta)*(180/M_PI));
        auto AoSeg = AoSec - AoT;
        return std::floor(AoSeg * (vt/M_PI*r * r));
    }
};

int main(int argc, char const* argv[])
{
    std::cout << VolTank::tankVol(40, 120, 3500) << '\n';
    return 0;
}
