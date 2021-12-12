#include <cstddef>
#include <cstdint>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::vector<std::vector<uint64_t>> values;

    std::string line;
    uint64_t flashes = 0;
    while (std::cin >> line) {
        std::vector<uint64_t> lineValues;
        for (auto c : line) {
            lineValues.push_back(c - '0');
        }
        values.push_back(lineValues);
    }

    for (size_t i = 0; i < 100; ++i) {
        std::stack<std::pair<size_t, size_t>> flashPositions;
        for (size_t y = 0; y < values.size(); ++y) {
            for (size_t x = 0; x < values[0].size(); ++x) {
                values[y][x]++;
                if (values[y][x] == 10) {
                    flashPositions.push(std::make_pair(x, y));
                }
            }
        }

        while (!flashPositions.empty()) {
            auto next = flashPositions.top();
            flashPositions.pop();
            int x = next.first;
            int y = next.second;
            values[y][x] = 0;
            flashes++;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    if (x + dx < 0 || y + dy < 0
                        || x + dx > values[0].size() - 1
                        || y + dy > values.size() - 1) {
                        continue;
                    }

                    if (values[y + dy][x + dx] != 0) {
                        values[y + dy][x + dx]++;
                        if (values[y + dy][x + dx] == 10) {
                            flashPositions.push(std::make_pair(x + dx, y + dy));
                        }
                    }
                }
            }
        }
    }

    std::cout << flashes << "\n";
}
