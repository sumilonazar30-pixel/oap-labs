#include <iostream>

int main() {
    constexpr int kMinN = 1;
    constexpr int kMaxN = 30;
    constexpr int kMinTemp = -100;
    constexpr int kMaxTemp = 100;
    constexpr int kL = -25;
    constexpr int kH = -5;

    int n;
    if (!(std::cin >> n) || n < kMinN || n > kMaxN) {
        std::cout << "Error: invalid n\n";
        return 1;
    }

    int below = 0;
    int inside = 0;
    int above = 0;

    for (int i = 0; i < n; ++i) {
        int t;
        if (!(std::cin >> t) || t < kMinTemp || t > kMaxTemp) {
            std::cout << "Error: invalid temperature\n";
            return 1;
        }

        if (t < kL) {
            ++below;
        } else if (t <= kH) {
            ++inside;
        } else {
            ++above;
        }
    }

    std::cout << "below = " << below << '\n';
    std::cout << "inside = " << inside << '\n';
    std::cout << "above = " << above << '\n';
    return 0;
}
