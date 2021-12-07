#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<uint64_t, uint64_t> positions;

    uint64_t pos;
    while (std::cin >> pos) {
        positions[pos]++;
        std::cin.ignore();
    }

    uint64_t target = std::max_element(positions.begin(),
                                       positions.end(),
                                       [](const auto &a, const auto &b) {
                                           return a.second < b.second;
                                       })
                              ->first;

    uint64_t dist = 0;
    for (auto &value : positions) {
        int64_t d = int64_t(value.first) - target;
        d = d < 0 ? -d : d;
        dist += d * value.second;
    }

    std::cout << dist << "\n";
}
