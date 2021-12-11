#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main() {
    const std::array<std::set<int>, 10> segments = {
            std::set<int>{0, 1, 2, 4, 5, 6},
            std::set<int>{2, 5},
            std::set<int>{0, 2, 3, 4, 6},
            std::set<int>{0, 2, 3, 5, 6},
            std::set<int>{1, 2, 3, 5},
            std::set<int>{0, 1, 3, 5, 6},
            std::set<int>{0, 1, 3, 4, 5, 6},
            std::set<int>{0, 2, 5},
            std::set<int>{0, 1, 2, 3, 4, 5, 6},
            std::set<int>{0, 1, 2, 3, 5, 6},
    };

    const std::set<int> allSegments = {0, 1, 2, 3, 4, 5, 6};

    uint64_t sum = 0;
    std::string front;
    while (std::getline(std::cin, front, '|')) {
        std::string back;
        std::getline(std::cin, back);

        std::array<std::set<int>, 7> possibilities;
        for (size_t i = 0; i < 7; ++i) {
            possibilities[i] = std::set<int>{0, 1, 2, 3, 4, 5, 6};
        }

        std::string signal;
        std::stringstream signalStream{front};
        while (signalStream >> signal) {
            std::set<int> possible;
            std::set<int> impossible;

            for (auto segment : segments) {
                if (segment.size() == signal.size()) {
                    std::set<int> result;
                    std::set_union(possible.begin(),
                                   possible.end(),
                                   segment.begin(),
                                   segment.end(),
                                   std::inserter(result, result.begin()));
                    possible = result;

                    std::set<int> opposite;
                    std::set_difference(
                            allSegments.begin(),
                            allSegments.end(),
                            segment.begin(),
                            segment.end(),
                            std::inserter(opposite, opposite.begin()));

                    result.clear();
                    std::set_union(impossible.begin(),
                                   impossible.end(),
                                   opposite.begin(),
                                   opposite.end(),
                                   std::inserter(result, result.begin()));
                    impossible = result;
                }
            }
            for (char c = 'a'; c <= 'g'; c++) {
                std::set<int> result;
                if (signal.find(c) != std::string::npos) {
                    std::set_intersection(
                            possibilities[c - 'a'].begin(),
                            possibilities[c - 'a'].end(),
                            possible.begin(),
                            possible.end(),
                            std::inserter(result, result.begin()));
                } else {
                    std::set_intersection(
                            possibilities[c - 'a'].begin(),
                            possibilities[c - 'a'].end(),
                            impossible.begin(),
                            impossible.end(),
                            std::inserter(result, result.begin()));
                }
                possibilities[c - 'a'] = result;
            }
        }

        std::vector<std::set<int>> remaining{possibilities.begin(),
                                             possibilities.end()};

        std::array<int, 7> mappings;
        for (int i = 0; i < 7; ++i) {
            for (size_t i = 0; i < remaining.size(); i++) {
                if (remaining[i].size() == 1) {
                    auto elem = *remaining[i].begin();

                    for (auto &set : remaining) {
                        auto it = set.find(elem);
                        if (it != set.end()) {
                            set.erase(it);
                        }
                    }

                    mappings[i] = elem;

                    break;
                }
            }
        }

        std::stringstream outputStream{back};
        uint64_t val = 0;
        while (outputStream >> signal) {
            std::set<int> input;
            for (auto c : signal) {
                input.insert(mappings[c - 'a']);
            }

            for (size_t i = 0; i < segments.size(); ++i) {
                if (segments[i] == input) {
                    val = val * 10 + i;
                    break;
                }
            }
        }
        sum += val;
    }
    std::cout << sum << "\n";
}
