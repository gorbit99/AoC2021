#include <iostream>

int main() {
    int window[4];
    for (int i = 0; i < 3; ++i) {
        std::cin >> window[i];
    }
    size_t increases = 0;
    for (size_t curIndex = 3; std::cin >> window[curIndex];
         curIndex = (curIndex + 1) % 4) {
        if (window[curIndex] > window[(curIndex + 1) % 4]) {
            increases++;
        }
    }
    std::cout << increases << "\n";
}
