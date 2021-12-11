#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string front;
    size_t identifiables = 0;
    while (std::getline(std::cin, front, '|')) {
        std::string back;
        std::getline(std::cin, back);
        std::stringstream ss{back};
        std::string signal;
        while (ss >> signal) {
            if (signal.length() == 2 || signal.length() == 3
                || signal.length() == 4 || signal.length() == 7) {
                identifiables++;
            }
        }
    }

    std::cout << identifiables << "\n";
}
