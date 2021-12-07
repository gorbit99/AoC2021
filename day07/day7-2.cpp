#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<uint64_t, uint64_t> positions;

    uint64_t pos;
    uint64_t inputNum = 0;
    while (std::cin >> pos) {
        inputNum++;
        positions[pos]++;
        std::cin.ignore();
    }

    uint64_t sum = 0;
    for (auto &i : positions) {
        sum += i.first * i.second;
    }

    double target = double(sum) / inputNum;

    uint64_t dist1 = 0;
    for (auto &value : positions) {
        int64_t curTarget = std::floor(target);
        int64_t d = int64_t(value.first) - curTarget;
        d = d < 0 ? -d : d;
        d = d * (d + 1) / 2;
        dist1 += d * value.second;
    }

    uint64_t dist2 = 0;
    for (auto &value : positions) {
        int64_t curTarget = std::ceil(target);
        int64_t d = int64_t(value.first) - curTarget;
        d = d < 0 ? -d : d;
        d = d * (d + 1) / 2;
        dist2 += d * value.second;
    }

    uint64_t dist = dist1 > dist2 ? dist2 : dist1;

    std::cout << dist << "\n";
}
