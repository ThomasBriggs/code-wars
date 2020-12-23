#include <iostream>

class Arge
{
  public:
  static int nbYear(int p0, double percent, int aug, int p);
};

int Arge::nbYear(int p0, double percent, int aug, int p) {
    int years = 0;
    while (p0 < p) {
        p0 = p0 + (p0 * (percent/100)) + aug;
        years++;
    }
    return years;
}

int main(int argc, char const *argv[])
{
    int years = Arge::nbYear(1500000, 2.5, 10000, 2000000);
    std::cout << "Years: " << years << std::endl;
    return 0;
}
