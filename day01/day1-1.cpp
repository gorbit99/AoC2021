#include <iostream>

int main() {
    int number;
    int prevNumber;
    std::cin >> prevNumber;
    size_t increases = 0;
    while (std::cin >> number) {
        if (number > prevNumber) {
            increases++;
        }
        prevNumber = number;
    }
    std::cout << increases << "\n";
}
