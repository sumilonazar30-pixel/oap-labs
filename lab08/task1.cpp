#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    constexpr int kFirstIndex = -2;
    constexpr int kLastIndex = 2;
    constexpr double kStep = 0.5;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::setw(12) << "x\\y";
    for (int j = kFirstIndex; j <= kLastIndex; ++j) {
        const double y = j * kStep;
        std::cout << std::setw(12) << y;
    }
    std::cout << '\n';

    for (int i = kFirstIndex; i <= kLastIndex; ++i) {
        const double x = i * kStep;
        std::cout << std::setw(12) << x;

        for (int j = kFirstIndex; j <= kLastIndex; ++j) {
            const double y = j * kStep;
            if (x - y >= 0.0) {
                std::cout << std::setw(12) << std::sqrt(x - y);
            } else {
                std::cout << std::setw(12) << "undefined";
            }
        }
        std::cout << '\n';
    }

    return 0;
}
