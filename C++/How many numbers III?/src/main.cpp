#include <cstdint>
#include <iostream>
#include <optional>
#include <tuple>
#include <vector>

using out_t = std::tuple<std::uint32_t, std::uint64_t, std::uint64_t>;

std::uint32_t sum(const std::vector<uint8_t>& digits)
{
    std::uint32_t sum = 0;
    for (auto&& i : digits)
        sum += i;
    return sum;
}

bool init(std::vector<uint8_t>& digits, const std::uint32_t& digit_sum)
{

    size_t size = digits.size();

}

std::optional<out_t> find_all(std::uint32_t digit_sum, std::uint32_t digit_count)
{

    if (digit_sum < digit_count)
        return std::nullopt;
    if (digit_sum > digit_count * 9)
        return std::nullopt;

    std::vector<uint8_t> digits(digit_count, 0);
    std::uint32_t count;
    std::uint64_t min;
    std::uint64_t max;
}

int main()
{
    std::cout << "Hello, World!" << '\n';
    return 0;
}
