#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
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

    std::vector<uint64_t> basins;

    for (size_t y = 0; y < values.size(); ++y) {
        for (size_t x = 0; x < values[0].size(); ++x) {
            if (values[y][x] < 9) {
                std::stack<std::pair<size_t, size_t>> stack;
                stack.push(std::make_pair(x, y));
                values[y][x] = 9;
                uint64_t size = 0;

                while (!stack.empty()) {
                    auto next = stack.top();
                    stack.pop();
                    size++;
                    size_t dx = next.first;
                    size_t dy = next.second;
                    if (dx > 0 && values[dy][dx - 1] < 9) {
                        values[dy][dx - 1] = 9;
                        stack.push(std::make_pair(dx - 1, dy));
                    }
                    if (dy > 0 && values[dy - 1][dx] < 9) {
                        values[dy - 1][dx] = 9;
                        stack.push(std::make_pair(dx, dy - 1));
                    }
                    if (dx < values[0].size() - 1 && values[dy][dx + 1] < 9) {
                        values[dy][dx + 1] = 9;
                        stack.push(std::make_pair(dx + 1, dy));
                    }
                    if (dy < values.size() - 1 && values[dy + 1][dx] < 9) {
                        values[dy + 1][dx] = 9;
                        stack.push(std::make_pair(dx, dy + 1));
                    }
                }
                basins.push_back(size);
            }
        }
    }

    std::sort(basins.begin(), basins.end(), [](const auto a, const auto b) {
        return a > b;
    });

    uint64_t result = 1;
    for (size_t i = 0; i < 3; ++i) {
        result *= basins[i];
    }

    std::cout << result << "\n";
}
