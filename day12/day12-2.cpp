#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

struct State {
    std::string location;
    std::set<std::string> visitedSmallCaves;
    bool visitedSmallTwice;

    State(std::string location,
          std::set<std::string> visitedSmallCaves,
          bool visitedSmallTwice)
            : location{location},
              visitedSmallCaves{visitedSmallCaves},
              visitedSmallTwice{visitedSmallTwice} {
    }
};

int main() {
    std::unordered_map<std::string, std::set<std::string>> passages;

    std::string a;
    while (std::getline(std::cin, a, '-')) {
        std::string b;
        std::getline(std::cin, b);

        if (b != "start") {
            passages[a].insert(b);
        }
        if (a != "start") {
            passages[b].insert(a);
        }
    }

    std::stack<State> stack;
    stack.push(State{"start", {}, false});

    uint64_t paths = 0;
    while (!stack.empty()) {
        auto top = stack.top();
        stack.pop();

        auto &possiblePassages = passages[top.location];
        std::set<std::string> diff;
        std::set_difference(possiblePassages.begin(),
                            possiblePassages.end(),
                            top.visitedSmallCaves.begin(),
                            top.visitedSmallCaves.end(),
                            std::inserter(diff, diff.begin()));
        for (auto &passage : diff) {
            if (passage == "end") {
                paths++;
                continue;
            }
            stack.emplace(passage,
                          top.visitedSmallCaves,
                          top.visitedSmallTwice);
            if (passage[0] >= 'a') {
                stack.top().visitedSmallCaves.insert(passage);
            }
        }
        if (!top.visitedSmallTwice) {
            std::set<std::string> intersection;
            std::set_intersection(
                    possiblePassages.begin(),
                    possiblePassages.end(),
                    top.visitedSmallCaves.begin(),
                    top.visitedSmallCaves.end(),
                    std::inserter(intersection, intersection.begin()));
            for (auto &passage : intersection) {
                stack.emplace(passage, top.visitedSmallCaves, true);
            }
        }
    }

    std::cout << paths << "\n";
}
