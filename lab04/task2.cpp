// ЛР04. Завдання 2. Варіант 11
// f1=x^2+x+1 при x<1;
// f2=sqrt(4-x) при 1<=x<=4;
// f3=1/(x-5) при x>4.
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double x = 0.0;

    std::cout << "Enter x: ";
    if (!(std::cin >> x)) {
        std::cerr << "Invalid input: expected a number.\n";
        return 1;
    }

    double y = 0.0;
    int branch = 0;

    if (x < 1.0) {
        branch = 1;
        y = x * x + x + 1.0;
    } else if (x <= 4.0) {
        branch = 2;
        if (4.0 - x < 0.0) {
            std::cerr << "Error: square root argument must be non-negative.\n";
            return 1;
        }
        y = std::sqrt(4.0 - x);
    } else {
        branch = 3;
        if (std::fabs(x - 5.0) < 1e-9) {
            std::cerr << "Error: division by zero at x = 5.\n";
            return 1;
        }
        y = 1.0 / (x - 5.0);
    }

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "x = " << x << ", branch = " << branch
              << ", y = " << y << '\n';

    return 0;
}
