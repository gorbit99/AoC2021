#include <array>
#include <cstdint>
#include <iostream>

int main() {
    std::array<uint64_t, 9> fishes{0};

    uint64_t age;
    while (std::cin >> age) {
        fishes[age]++;
        std::cin.ignore();
    }

    for (int i = 0; i < 256; ++i) {
        uint64_t next = fishes.at(0);
        for (size_t j = 1; j < 9; ++j) {
            fishes[j - 1] = fishes[j];
        }
        fishes[8] = next;
        fishes[6] += next;
    }

    uint64_t sum = 0;
    for (auto fish : fishes) {
        sum += fish;
    }

    std::cout << sum << "\n";
}
