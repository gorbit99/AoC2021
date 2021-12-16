#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

namespace std {
    template<typename A, typename B>
    struct hash<pair<A, B>> {
        size_t operator()(const std::pair<A, B> pair) const {
            return hash<A>{}(pair.first) ^ hash<B>{}(pair.second);
        }
    };
} // namespace std

int main() {
    std::unordered_set<std::pair<int64_t, int64_t>> points;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.size() == 0) {
            break;
        }
        std::stringstream ss{line};
        int64_t x;
        int64_t y;
        ss >> x;
        ss.ignore();
        ss >> y;
        points.insert(std::make_pair(x, y));
    }

    while (std::cin.ignore(11)) {
        char d;
        std::cin >> d;
        std::cin.ignore();
        int64_t coord;
        std::cin >> coord;

        std::unordered_set<std::pair<int64_t, int64_t>> transformed;

        std::transform(points.begin(),
                       points.end(),
                       std::inserter(transformed, transformed.begin()),
                       [&](auto &point) {
                           int64_t x = point.first;
                           int64_t y = point.second;
                           if (d == 'x') {
                               x = coord - std::labs(x - coord);
                           } else {
                               y = coord - std::labs(y - coord);
                           }
                           return std::make_pair(x, y);
                       });
        points = transformed;
    }

    int64_t maxX = std::numeric_limits<int64_t>::min();
    int64_t maxY = std::numeric_limits<int64_t>::min();

    for (auto point : points) {
        if (point.first > maxX) {
            maxX = point.first;
        }
        if (point.second > maxY) {
            maxY = point.second;
        }
    }

    std::vector<std::vector<bool>> map;
    map.resize(maxY + 1);
    for (int64_t y = 0; y <= maxY; y++) {
        map.at(y).resize(maxX + 1);
    }

    for (auto point : points) {
        map.at(point.second).at(point.first) = true;
    }

    for (int64_t y = 0; y <= maxY; y++) {
        for (int64_t x = 0; x <= maxX; x++) {
            std::cout << (map.at(y).at(x) ? '#' : ' ');
        }
        std::cout << "\n";
    }
}
