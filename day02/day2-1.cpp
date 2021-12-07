#include <iostream>
#include <string>

int main() {
    int x = 0;
    int y = 0;
    std::string command;
    while (std::cin >> command) {
        int amount;
        std::cin >> amount;
        if (command == "forward") {
            x += amount;
        } else if (command == "up") {
            y -= amount;
        } else if (command == "down") {
            y += amount;
        }
    }

    std::cout << (x * y) << "\n";
}
