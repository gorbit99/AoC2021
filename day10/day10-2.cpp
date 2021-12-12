#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <vector>

int main() {
    const std::string forwardParens = "([{<";
    const std::string backwardParens = ")]}>";
    const std::array<uint64_t, 4> scores{1, 2, 3, 4};

    std::vector<uint64_t> scored;

    std::string line;
    while (std::cin >> line) {
        std::stack<char> parens;

        bool complete = true;
        for (auto c : line) {
            if (forwardParens.find(c) != std::string::npos) {
                parens.push(c);
            } else {
                char should = parens.top();
                parens.pop();

                size_t parenIndex = backwardParens.find(c);
                if (forwardParens[parenIndex] != should) {
                    complete = false;
                    break;
                }
            }
        }

        if (!complete) {
            continue;
        }

        uint64_t curScore = 0;
        while (!parens.empty()) {
            char paren = parens.top();
            parens.pop();

            size_t parenIndex = forwardParens.find(paren);
            curScore = curScore * 5 + scores[parenIndex];
        }
        scored.push_back(curScore);
    }

    std::sort(scored.begin(), scored.end());

    std::cout << scored[scored.size() / 2] << "\n";
}
