#include <iostream>
#include <chrono>

bool isPrime(long long n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}

int main(int argc, char const *argv[])
{
    using  namespace std::chrono;
    auto start = high_resolution_clock::now();
    std::cout << isPrime(119709697) << std::endl;
    auto stop = high_resolution_clock::now();
    std::cout << duration_cast<microseconds>(stop-start).count() << std::endl;
    return 0;
}


