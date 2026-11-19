// ЛР02. Частина В. Варіант 11
// Кількість учнів і кількість місць за партою -> потрібна кількість парт.
#include <iostream>

int main() {
    int students = 0;
    int seatsPerDesk = 2;

    std::cout << "Enter number of students and seats per desk: ";
    if (!(std::cin >> students >> seatsPerDesk)) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    if (students < 0 || seatsPerDesk <= 0) {
        std::cerr << "Students must be non-negative and seats per desk positive.\n";
        return 1;
    }

    const int desks = (students + seatsPerDesk - 1) / seatsPerDesk;
    std::cout << "Desks needed = " << desks << '\n';

    return 0;
}
