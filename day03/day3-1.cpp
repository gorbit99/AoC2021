#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> input;

    std::string line;
    while (std::cin >> line) {
        input.push_back(line);
    }

    uint64_t gamma = 0;
    uint64_t epsilon = 0;
    size_t lineLength = input.at(0).length();

    for (size_t i = 0; i < lineLength; i++) {
        int64_t sum = 0;
        for (auto &line : input) {
            sum += line.at(i) == '0' ? -1 : 1;
        }
        gamma <<= 1;
        epsilon <<= 1;
        if (sum > 0) {
            gamma |= 1;
        } else {
            epsilon |= 1;
        }
    }

    std::cout << (gamma * epsilon) << "\n";
}
