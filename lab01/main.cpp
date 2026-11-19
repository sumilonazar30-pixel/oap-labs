// ЛР01. Налаштування середовища розробки. Варіант 11
// Шумило Назар, група 21КІ
#include <iostream>

int main() {
    std::cout << "Student: Shumylo Nazar\n";
    std::cout << "Group:   21KI\n";
    std::cout << "Variant: 11\n";

#if defined(_MSC_VER)
    std::cout << "Compiler: MSVC " << _MSC_VER
              << ", standard " << _MSVC_LANG << '\n';
#elif defined(__clang__)
    std::cout << "Compiler: clang " << __clang_major__
              << ", standard " << __cplusplus << '\n';
#elif defined(__GNUC__)
    std::cout << "Compiler: g++ " << __GNUC__ << '.'
              << __GNUC_MINOR__ << ", standard " << __cplusplus << '\n';
#endif

    return 0;
}
