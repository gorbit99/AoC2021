#include <cstdint>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct State {
    std::string location;
    std::unordered_set<std::string> visitedSmallCaves;
};

int main() {
    std::unordered_map<std::string, std::vector<std::string>> passages;

    std::string a;
    while (std::getline(std::cin, a, '-')) {
        std::string b;
        std::getline(std::cin, b);

        passages[a].push_back(b);
        passages[b].push_back(a);
    }

    std::stack<State> stack;
    stack.push(State{"start", {"start"}});

    uint64_t paths = 0;
    while (!stack.empty()) {
        auto top = stack.top();
        stack.pop();

        if (top.location == "end") {
            paths++;
            continue;
        }

        auto &possiblePassages = passages[top.location];
        for (auto &passage : possiblePassages) {
            if (passage[0] < 'a'
                || top.visitedSmallCaves.find(passage)
                           == top.visitedSmallCaves.end()) {
                State nextState{passage, top.visitedSmallCaves};
                if (passage[0] >= 'a') {
                    nextState.visitedSmallCaves.insert(passage);
                }
                stack.push(nextState);
            }
        }
    }

    std::cout << paths << "\n";
}
