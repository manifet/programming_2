#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void quickSort(std::vector<int>& array, int startIdx, int endIdx) {
    if (startIdx < endIdx) {
        int pivotValue = array[endIdx];
        int lastSmallerIdx = startIdx - 1;

        for (int currentIdx = startIdx; currentIdx < endIdx; currentIdx++) {
            if (array[currentIdx] < pivotValue) { 
                lastSmallerIdx++; 
                std::swap(array[lastSmallerIdx], array[currentIdx]); 
            }
        }

        std::swap(array[lastSmallerIdx + 1], array[endIdx]);
        int pivotIdx = lastSmallerIdx + 1;

        quickSort(array, startIdx, pivotIdx - 1);
        quickSort(array, pivotIdx + 1, endIdx);
    }
}

int main() {
    const int ARRAY_SIZE = 1000;
    std::vector<int> numbers(ARRAY_SIZE);

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 10000;
    }

    quickSort(numbers, 0, ARRAY_SIZE - 1);

    std::cout << "Отсортированный массив:\n";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}