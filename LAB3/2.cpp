#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void quickSort(std::vector<int>& numbers, int leftBound, int rightBound) {
    int leftIndex = leftBound;
    int rightIndex = rightBound;
    int pivotValue = numbers[(leftBound + rightBound) / 2];

    while (leftIndex <= rightIndex) {
        while (numbers[leftIndex] < pivotValue) {
            leftIndex++;
        }
        while (numbers[rightIndex] > pivotValue) {
            rightIndex--;
        }
        if (leftIndex <= rightIndex) {
            std::swap(numbers[leftIndex], numbers[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
    }

    if (leftBound < rightIndex) {
        quickSort(numbers, leftBound, rightIndex);
    }
    if (leftIndex < rightBound) {
        quickSort(numbers, leftIndex, rightBound);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    const int ARRAY_SIZE = 20;
    std::vector<int> randomNumbers(ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        randomNumbers[i] = rand() % 51 + 50;
    }

    std::cout << "Изначальный массив: ";
    for (const auto& number : randomNumbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    quickSort(randomNumbers, 0, ARRAY_SIZE - 1);

    std::cout << "Сортированные массив: ";
    for (const auto& number : randomNumbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}