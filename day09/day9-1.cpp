#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::vector<uint32_t>> values;
    std::string line;
    while (std::cin >> line) {
        std::vector<uint32_t> lineValues;
        for (auto c : line) {
            lineValues.push_back(c - '0');
        }
        values.push_back(lineValues);
    }

    uint64_t lowPoints = 0;
    for (size_t y = 0; y < values.size(); ++y) {
        for (size_t x = 0; x < values[0].size(); ++x) {
            if ((x == 0 || values[y][x - 1] > values[y][x])
                && (y == 0 || values[y - 1][x] > values[y][x])
                && (x == values[0].size() - 1
                    || values[y][x + 1] > values[y][x])
                && (y == values.size() - 1
                    || values[y + 1][x] > values[y][x])) {
                lowPoints += values[y][x] + 1;
            }
        }
    }

    std::cout << lowPoints << "\n";
}
