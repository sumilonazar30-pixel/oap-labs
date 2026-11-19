// ЛР03. Завдання 1. Формули трикутника за Героном
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    std::cout << "Enter three sides: ";
    std::cin >> a >> b >> c;

    const double p = (a + b + c) / 2.0;
    const double area = std::sqrt(p * (p - a) * (p - b) * (p - c));
    const double inradius = area / p;
    const double circumradius = (a * b * c) / (4.0 * area);
    const double heightA = 2.0 * area / a;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(20) << "Semiperimeter"
              << std::right << p << '\n';
    std::cout << std::left << std::setw(20) << "Area"
              << std::right << area << '\n';
    std::cout << std::left << std::setw(20) << "Inradius"
              << std::right << inradius << '\n';
    std::cout << std::left << std::setw(20) << "Circumradius"
              << std::right << circumradius << '\n';
    std::cout << std::left << std::setw(20) << "Height to side a"
              << std::right << heightA << '\n';

    return 0;
}
