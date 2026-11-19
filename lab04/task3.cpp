// ЛР04. Завдання 3. Варіант 11 — переведення одиниць довжини в метри.
#include <iostream>
#include <iomanip>

int main() {
    int unitCode = 0;
    double length = 0.0;
    double factor = 0.0;
    const char* unitName = "";

    std::cout << "Enter unit code (1 mm, 2 cm, 3 m, 4 km, 5 inch, 6 mile) and length: ";
    if (!(std::cin >> unitCode >> length)) {
        std::cerr << "Error: invalid input.\n";
        return 1;
    }

    if (length < 0.0 || length > 10000.0) {
        std::cerr << "Error: length must be in range 0..10000.\n";
        return 1;
    }

    switch (unitCode) {
        case 1:
            factor = 0.001;
            unitName = "mm";
            break;
        case 2:
            factor = 0.01;
            unitName = "cm";
            break;
        case 3:
            factor = 1.0;
            unitName = "m";
            break;
        case 4:
            factor = 1000.0;
            unitName = "km";
            break;
        case 5:
            factor = 0.0254;
            unitName = "inch";
            break;
        case 6:
            factor = 1609.344;
            unitName = "mile";
            break;
        default:
            std::cerr << "Error: incorrect unit code.\n";
            return 1;
    }

    const double meters = length * factor;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << length << ' ' << unitName << " = " << meters << " m\n";

    return 0;
}
