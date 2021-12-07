#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <unordered_map>

struct Pos {
public:
    int64_t x;
    int64_t y;

    bool operator==(const Pos &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Pos &other) const {
        return !(*this == other);
    }
};

namespace std {
    template<>
    struct hash<Pos> {
        std::size_t operator()(const Pos &pos) const {
            return hash<int64_t>()(pos.x) ^ hash<int64_t>()(pos.y);
        }
    };
} // namespace std

int main() {
    std::unordered_map<Pos, uint64_t> positions;

    while (true) {
        Pos posA;
        Pos posB;
        if (!(std::cin >> posA.x)) {
            break;
        }
        std::cin.ignore();
        std::cin >> posA.y;
        std::cin.ignore(4);
        std::cin >> posB.x;
        std::cin.ignore();
        std::cin >> posB.y;

        if (posA.x != posB.x && posA.y != posB.y) {
            continue;
        }

        int dx = posA.x < posB.x ? 1 : (posA.x > posB.x ? -1 : 0);
        int dy = posA.y < posB.y ? 1 : (posA.y > posB.y ? -1 : 0);

        positions[posA]++;
        while (posA != posB) {
            posA.x += dx;
            posA.y += dy;

            positions[posA]++;
        }
    }

    uint64_t overlap =
            std::count_if(positions.begin(),
                          positions.end(),
                          [](const auto &val) { return val.second > 1; });

    std::cout << overlap << "\n";
}
