#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    

// Функция быстрой сортировки
void quickSort(std::vector<int>& array, int startIdx, int endIdx) {
    if (startIdx < endIdx) {
        // Опорный элемент (pivot) - последний элемент подмассива
        int pivotValue = array[endIdx];
        // Индекс последнего элемента, меньшего опорного
        int lastSmallerIdx = startIdx - 1;

        // Разделение: перераспределение элементов относительно опорного
        for (int currentIdx = startIdx; currentIdx < endIdx; currentIdx++) {
            if (array[currentIdx] < pivotValue) { 
                lastSmallerIdx++; 
                std::swap(array[lastSmallerIdx], array[currentIdx]); 
            }
        }

        // Помещаем опорный элемент на правильную позицию
        std::swap(array[lastSmallerIdx + 1], array[endIdx]);
        int pivotIdx = lastSmallerIdx + 1;  // Окончательная позиция опорного элемента

        // Рекурсивно сортируем подмассивы слева и справа от опорного элемента
        quickSort(array, startIdx, pivotIdx - 1);
        quickSort(array, pivotIdx + 1, endIdx);
    }
}

int main() {
    const int ARRAY_SIZE = 1000;           // Размер массива для сортировки
    std::vector<int> numbers(ARRAY_SIZE);  // Вектор для хранения чисел

    // Инициализация генератора случайных чисел текущим временем
    srand(static_cast<unsigned int>(time(0)));

    // Заполнение массива случайными числами от 0 до 9999
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 10000;
    }

    // Вызов быстрой сортировки для всего массива
    quickSort(numbers, 0, ARRAY_SIZE - 1);

    // Вывод отсортированного массива
    std::cout << "Отсортированный массив:\n";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}