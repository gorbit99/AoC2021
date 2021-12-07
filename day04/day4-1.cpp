#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

class Board {
public:
    friend std::istream &operator>>(std::istream &istream, Board &board) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                int number;
                if (std::cin >> number) {
                    board.values[y][x] = number;
                } else {
                    return istream;
                }
            }
        }

        return istream;
    }

    void map_onto_indices(std::vector<int> &numbers) {
        for (auto &row : values) {
            for (auto &value : row) {
                value = std::distance(
                        numbers.begin(),
                        std::find(numbers.begin(), numbers.end(), value));
            }
        }
    }

    int first_win() {
        int min_win = std::numeric_limits<int>::max();
        for (auto &row : values) {
            int max = *std::max_element(row.begin(), row.end());
            if (max < min_win) {
                min_win = max;
            }
        }

        for (size_t i = 0; i < 5; i++) {
            int max = -1;
            for (auto &row : values) {
                if (row[i] > max) {
                    max = row[i];
                }
            }
            if (max < min_win) {
                min_win = max;
            }
        }
        return min_win;
    }

    int calculate_score(std::vector<int> &called, int win) {
        int sum = 0;
        for (auto &row : values) {
            for (auto val : row) {
                if (val > win) {
                    sum += called[val];
                }
            }
        }
        return sum;
    }

private:
    std::array<std::array<int, 5>, 5> values;
};

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss{line};
    std::vector<int> numbers;
    int number;
    while (ss >> number) {
        numbers.push_back(number);
        ss.ignore();
    }

    Board best_board;
    Board board;
    int min_win = numbers.size() + 1;
    while (std::cin >> board) {
        board.map_onto_indices(numbers);

        int win = board.first_win();
        if (win < min_win) {
            min_win = win;
            best_board = board;
        }
    }
    std::cout << (best_board.calculate_score(numbers, min_win)
                  * numbers[min_win])
              << "\n";
    return 1;
}
