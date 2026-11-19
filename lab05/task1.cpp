// ЛР05. Табулювання функції однієї змінної. Варіант 11
// Шумило Назар, група 21КІ, 2026-11-19

#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    constexpr double a = -2.0;
    constexpr double h = 0.5;
    constexpr int row_count = 9;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "i\tx\ty\n";

    for (int i = 0; i < row_count; ++i) {
        const double x = a + i * h;
        const double denominator = x - 0.5;

        std::cout << i << '\t' << x << '\t';

        if (denominator == 0.0) {
            std::cout << "undefined\n";
        } else {
            double y = std::sin(x) / denominator;

            // Уникаємо виведення -0.0000 для математичного нуля.
            if (std::abs(y) < 0.00005) {
                y = 0.0;
            }

            std::cout << y << '\n';
        }
    }

    return 0;
}
