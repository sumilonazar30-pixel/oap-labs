// ЛР04. Завдання 1. Розв'язання квадратного рівняння
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    std::cout << "Enter a, b, c: ";
    if (!(std::cin >> a >> b >> c)) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(4);

    if (a == 0.0) {
        if (b == 0.0) {
            if (c == 0.0) {
                std::cout << "Any x is a solution.\n";
            } else {
                std::cout << "No roots.\n";
            }
        } else {
            const double x = -c / b;
            std::cout << "Linear equation: x = " << x << '\n';
        }
    } else {
        const double discriminant = b * b - 4.0 * a * c;

        if (discriminant < 0.0) {
            std::cout << "No real roots.\n";
        } else if (std::fabs(discriminant) < 1e-9) {
            const double x = -b / (2.0 * a);
            std::cout << "One root: x = " << x << '\n';
        } else {
            const double rootD = std::sqrt(discriminant);
            const double x1 = (-b - rootD) / (2.0 * a);
            const double x2 = (-b + rootD) / (2.0 * a);
            std::cout << "Two roots: x1 = " << x1
                      << ", x2 = " << x2 << '\n';
        }
    }

    return 0;
}
