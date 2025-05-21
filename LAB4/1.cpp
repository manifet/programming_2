#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    std::unordered_set<int> positiveNumbers;
    int value;

    while (input >> value) {
        if (value > 0) {
            positiveNumbers.insert(value);
        } else if (value < 0) {
            positiveNumbers.erase(-value);
        } else {
            std::vector<int> sortedValues(positiveNumbers.begin(), positiveNumbers.end());
            std::sort(sortedValues.begin(), sortedValues.end());

            for (int number : sortedValues) {
                output << number << " ";
            }
            output << std::endl;
            break;
        }
    }

    input.close();
    output.close();
    return 0;
}