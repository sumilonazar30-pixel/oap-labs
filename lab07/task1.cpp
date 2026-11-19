#include <iomanip>
#include <iostream>

int main() {
    constexpr int kA = 3;
    constexpr int kB = 0;
    constexpr int kC = 3;

    int n;
    if (!(std::cin >> n) || n < 1 || n > 20) {
        std::cout << "Error: n must be in range 1..20\n";
        return 1;
    }

    double sum = 0.0;

    for (int i = 1; i <= n; ++i) {
        const double term =
            static_cast<double>(kA * i + kB) / (i + kC);
        sum += term;
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "S = " << sum << '\n';
    return 0;
}
