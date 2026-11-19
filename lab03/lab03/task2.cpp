// ЛР03. Завдання 2. Варіант 11 — складні відсотки
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double principal = 1000.0;
    double rate = 7.5;
    double years = 5.0;

    std::cout << "Enter principal, annual rate (%) and years: ";
    std::cin >> principal >> rate >> years;

    const double amount = principal * std::pow(1.0 + rate / 100.0, years);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Principal = " << principal << '\n';
    std::cout << "Rate (%) = " << rate << '\n';
    std::cout << "Years = " << years << '\n';
    std::cout << "Final amount = " << amount << '\n';

    return 0;
}
