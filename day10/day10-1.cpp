#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>

int main() {
    const std::string forwardParens = "([{<";
    const std::string backwardParens = ")]}>";
    const std::array<uint64_t, 4> scores{3, 57, 1197, 25137};

    std::string line;
    size_t score = 0;
    while (std::cin >> line) {
        std::stack<char> parens;

        for (auto c : line) {
            if (forwardParens.find(c) != std::string::npos) {
                parens.push(c);
            } else {
                char should = parens.top();
                parens.pop();

                size_t parenIndex = backwardParens.find(c);
                if (forwardParens[parenIndex] != should) {
                    score += scores[parenIndex];
                    continue;
                }
            }
        }
    }
    std::cout << score << "\n";
}
