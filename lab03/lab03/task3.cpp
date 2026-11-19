// ЛР03. Завдання 3. Варіант 11 — сума і добуток цифр чотиризначного числа,
// а також число у зворотному порядку.
#include <iostream>

int main() {
    int number = 0;

    std::cout << "Enter a four-digit number: ";
    std::cin >> number;

    const int d1 = number / 1000;
    const int d2 = (number / 100) % 10;
    const int d3 = (number / 10) % 10;
    const int d4 = number % 10;

    const int digitSum = d1 + d2 + d3 + d4;
    const int digitProduct = d1 * d2 * d3 * d4;
    const int reversed = d4 * 1000 + d3 * 100 + d2 * 10 + d1;

    std::cout << "Sum of digits = " << digitSum << '\n';
    std::cout << "Product of digits = " << digitProduct << '\n';
    std::cout << "Reversed number = " << reversed << '\n';

    return 0;
}
