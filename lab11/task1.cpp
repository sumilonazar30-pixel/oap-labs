#include <array>
#include <charconv>
#include <iostream>
#include <string>

bool readInt(int& value) {
    std::string token;
    if (!(std::cin >> token)) {
        return false;
    }

    const char* begin = token.data();
    const char* end = begin + token.size();
    const auto parsed = std::from_chars(begin, end, value);
    return parsed.ec == std::errc{} && parsed.ptr == end;
}

int main() {
    constexpr int kCapacity = 11;
    constexpr int kScaleSize = 12;
    constexpr int kMinTemp = -100;
    constexpr int kMaxTemp = 100;

    std::array<int, kCapacity> temps{};
    int n = 0;

    if (!readInt(n) || n < 0 || n > 10) {
        std::cout << "Error: n out of range\n";
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (!readInt(temps[i])) {
            std::cout << "Error: invalid temperature\n";
            return 1;
        }
        if (temps[i] < kMinTemp || temps[i] > kMaxTemp) {
            std::cout << "Error: temperature out of range\n";
            return 1;
        }
    }

    int key = 0;
    if (!readInt(key) || key < kMinTemp || key > kMaxTemp) {
        std::cout << "Error: invalid search key\n";
        return 1;
    }

    std::array<int, kCapacity> selected{};
    int selectedCount = 0;

    for (int i = 0; i < n; ++i) {
        if (temps[i] >= 0 && temps[i] <= 20) {
            selected[selectedCount] = temps[i];
            ++selectedCount;
        }
    }

    std::cout << "selected (" << selectedCount << "):";
    for (int i = 0; i < selectedCount; ++i) {
        std::cout << ' ' << selected[i];
    }
    std::cout << '\n';

    int changedCount = 0;
    for (int i = 0; i < n; ++i) {
        if (temps[i] >= 0 && temps[i] <= 20) {
            temps[changedCount] = temps[i];
            ++changedCount;
        }
    }
    n = changedCount;

    std::cout << "changed (" << n << "):";
    for (int i = 0; i < n; ++i) {
        std::cout << ' ' << temps[i];
    }
    std::cout << '\n';

    int linearIndex = -1;
    int comparisons = 0;
    for (int i = 0; i < n; ++i) {
        ++comparisons;
        if (temps[i] == key) {
            linearIndex = i;
            break;
        }
    }

    std::cout << "linear: index " << linearIndex
              << ", comparisons " << comparisons << '\n';

    std::array<int, kScaleSize> scale{};
    for (int i = 0; i < kScaleSize; ++i) {
        scale[i] = i * i - 30;
    }

    bool increasing = true;
    for (int i = 1; i < kScaleSize; ++i) {
        if (scale[i] <= scale[i - 1]) {
            increasing = false;
            break;
        }
    }

    if (!increasing) {
        std::cout << "Error: scale is not increasing\n";
        return 2;
    }

    std::cout << "scale:";
    for (int i = 0; i < kScaleSize; ++i) {
        std::cout << ' ' << scale[i];
    }
    std::cout << '\n';

    int low = 0;
    int high = kScaleSize - 1;
    int binaryIndex = -1;
    int steps = 0;

    while (low <= high) {
        const int mid = low + (high - low) / 2;
        ++steps;

        if (scale[mid] == key) {
            binaryIndex = mid;
            break;
        }
        if (scale[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << "binary: index " << binaryIndex
              << ", steps " << steps << '\n';

    return 0;
}
