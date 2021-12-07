#include <iostream>
#include <string>

int main() {
    int x = 0;
    int y = 0;
    int aim = 0;
    std::string command;
    while (std::cin >> command) {
        int amount;
        std::cin >> amount;
        if (command == "forward") {
            x += amount;
            y += aim * amount;
        } else if (command == "up") {
            aim -= amount;
        } else if (command == "down") {
            aim += amount;
        }
    }

    std::cout << (x * y) << "\n";
}
