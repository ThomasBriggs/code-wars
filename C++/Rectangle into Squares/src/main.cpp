#include <vector>
#include <iostream>

class SqInRect
{
  public:
  static std::vector<int> sqInRect(int lng, int wdth);
   static std::vector<int> sqInRectV2(int lng, int wdth);
  
};

std::vector<int> SqInRect::sqInRect(int lng, int wdth) {
    std::vector<int> output;
    if (lng == wdth) return output;
    int largest =  std::max(lng, wdth);
    int smallest = std::min(lng, wdth);
    while (smallest != 0) {
        output.push_back(smallest);
        largest -= smallest;
        int largestTemp = std::max(largest, smallest);
        int smallestTemp = std::min(largest, smallest);
        largest = largestTemp;
        smallest = smallestTemp;
    }
    return output;
}


std::vector<int> SqInRect::sqInRectV2(int l, int w) {
    using namespace std;
    vector<int> ret;
    if (w == l) return ret;
    if (w > l) swap(l, w);
    while (w > 0) {
      ret.push_back(w);
      int t = w;
      w = l - w;
      l = t;
      if (w > l) swap(l, w);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    std::vector<int> test = SqInRect::sqInRect(5, 5);
    for (auto i: test) {
        std::cout << i << ' ';
    }
}
