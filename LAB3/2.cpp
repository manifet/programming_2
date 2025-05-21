#include <iostream>  
#include <vector> 
#include <cstdlib>  
#include <ctime> 

// Функция быстрой сортировки 
void quickSort(std::vector<int>& numbers, int leftBound, int rightBound) {
    int leftIndex = leftBound;           
    int rightIndex = rightBound;               
    int pivotValue = numbers[(leftBound + rightBound) / 2];  // Опорный элемент (средний по индексу)

    // Основной цикл сортировки
    while (leftIndex <= rightIndex) {
        // Поиск элемента, большего или равного опорному, слева
        while (numbers[leftIndex] < pivotValue) {
            leftIndex++;
        }
        // Поиск элемента, меньшего или равного опорному, справа
        while (numbers[rightIndex] > pivotValue) {
            rightIndex--;
        }
        // Обмен элементов, если левый индекс меньше или равен правому
        if (leftIndex <= rightIndex) {
            std::swap(numbers[leftIndex], numbers[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
    }

    // Рекурсивная сортировка левой и правой частей массива
    if (leftBound < rightIndex) {
        quickSort(numbers, leftBound, rightIndex);
    }
    if (leftIndex < rightBound) {
        quickSort(numbers, leftIndex, rightBound);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Инициализация генератора случайных чисел

    const int ARRAY_SIZE = 20;  // Размер массива
    std::vector<int> randomNumbers(ARRAY_SIZE); // Создание вектора на 20 элементов

    // Заполнение массива случайными числами от 50 до 100
    for (int i = 0; i < ARRAY_SIZE; i++) {
        randomNumbers[i] = rand() % 51 + 50;
    }

    // Вывод исходного массива
    std::cout << "Изначальный массив: ";
    for (const auto& number : randomNumbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    // Сортировка массива быстрой сортировкой
    quickSort(randomNumbers, 0, ARRAY_SIZE - 1);

    // Вывод отсортированного массива
    std::cout << "Сортированный массив: ";
    for (const auto& number : randomNumbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}
