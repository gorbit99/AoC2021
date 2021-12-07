#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> input;

    std::string line;
    while (std::getline(std::cin, line)) {
        input.push_back(line);
    }
    size_t inputLength = input.at(0).size();

    std::vector<std::string> oxygenData{input};
    std::vector<std::string> scrubberData{input};

    for (size_t i = 0; i < inputLength; i++) {
        int64_t sum = 0;
        for (auto &line : oxygenData) {
            sum += line.at(i) == '0' ? -1 : 1;
        }

        char curBit = sum >= 0 ? '1' : '0';

        oxygenData.erase(std::remove_if(oxygenData.begin(),
                                        oxygenData.end(),
                                        [&](const auto &value) {
                                            return value.at(i) != curBit;
                                        }),
                         oxygenData.end());

        if (oxygenData.size() == 1) {
            break;
        }
    }

    for (size_t i = 0; i < inputLength; i++) {
        int64_t sum = 0;
        for (auto &line : scrubberData) {
            sum += line.at(i) == '0' ? -1 : 1;
        }

        char curBit = sum >= 0 ? '0' : '1';

        scrubberData.erase(std::remove_if(scrubberData.begin(),
                                          scrubberData.end(),
                                          [&](const auto &value) {
                                              return value.at(i) != curBit;
                                          }),
                           scrubberData.end());

        if (scrubberData.size() == 1) {
            break;
        }
    }

    uint64_t oxygen = std::stoi(oxygenData.at(0), nullptr, 2);
    uint64_t scrubber = std::stoi(scrubberData.at(0), nullptr, 2);

    std::cout << (oxygen * scrubber) << "\n";
}
