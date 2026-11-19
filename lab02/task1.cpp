// ЛР02. Частина Б — виправлена програма діагностики
#include <iostream>

int square(int n);

int main() {
    int first = 0;
    int second = 0;

    std::cout << "Enter two integers (-100..100): ";
    if (!(std::cin >> first >> second)) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    if (first < -100 || first > 100 ||
        second < -100 || second > 100) {
        std::cerr << "Numbers must be in range -100..100.\n";
        return 1;
    }

    const int sum = first + second;
    std::cout << "Sum = " << sum << '\n';
    std::cout << "Square of sum = " << square(sum) << '\n';
    std::cout << "Average = " << static_cast<double>(sum) / 2 << '\n';

    return 0;
}

int square(int n) {
    return n * n;
}
