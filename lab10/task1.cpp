#include <array>
#include <charconv>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    constexpr int kMaxSize = 100;
    constexpr int kMinTemp = -100;
    constexpr int kMaxTemp = 100;

    std::array<int, kMaxSize> temps{};
    int n = 0;

    std::string token;
    while (std::cin >> token) {
        int value = 0;
        const char* begin = token.data();
        const char* end = begin + token.size();
        const auto parsed = std::from_chars(begin, end, value);

        if (parsed.ec != std::errc{} || parsed.ptr != end) {
            std::cout << "Error: invalid integer\n";
            return 1;
        }

        if (value == 999) {
            break;
        }

        if (value < kMinTemp || value > kMaxTemp) {
            std::cout << "Error: temperature out of range\n";
            return 1;
        }

        if (n == kMaxSize) {
            std::cout << "Error: too many readings\n";
            return 1;
        }

        temps[n] = value;
        ++n;
    }

    if (n == 0) {
        std::cout << "No data\n";
        return 0;
    }

    int maxChange = -1;
    int bestDay = 0;

    for (int i = 1; i < n; ++i) {
        int change = temps[i] - temps[i - 1];
        if (change < 0) {
            change = -change;
        }

        if (change > maxChange) {
            maxChange = change;
            bestDay = i + 1;
        }
    }

    if (n == 1) {
        std::cout << "No pairs\n";
    } else {
        std::cout << "max change = " << maxChange
                  << " (day " << bestDay << ")\n";
    }

    return 0;
}
