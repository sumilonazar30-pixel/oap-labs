#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    constexpr double kX = -1.0;
    constexpr double kEps = 1e-6;
    constexpr int kMaxTerms = 1000;

    double term = 1.0;
    double sum = term;
    int terms = 1;
    int n = 0;
    double bound = 0.0;
    bool converged = false;

    while (true) {
        const double nextTerm = term * kX / (n + 1.0);
        bound = std::fabs(nextTerm) /
                (1.0 - std::fabs(kX) / (n + 2.0));

        if (bound <= kEps) {
            converged = true;
            break;
        }

        if (terms == kMaxTerms) {
            break;
        }

        sum += nextTerm;
        term = nextTerm;
        ++terms;
        ++n;
    }

    std::cout << std::setprecision(12);
    if (!converged) {
        std::cout << "Not converged: term limit\n";
        return 2;
    }

    std::cout << "sum = " << sum << '\n';
    std::cout << "terms = " << terms << '\n';
    std::cout << "bound = " << bound << '\n';
    return 0;
}
