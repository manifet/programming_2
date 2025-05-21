#include <iostream>
#include <vector>
#include <random>

int main() {
  std::random_device rd;  // Источник энтропии
  std::mt19937 generator(rd());  // Генератор 
  
  // Константы для генерации случайных чисел
  const size_t MAX_N = 20;     // Максимальное количество элементов в векторе
  const size_t MINIMUM = 2;    // Минимальное значение элемента
  const size_t MAXIMUM = 103;   // Максимальное значение элемента

  // Создание вектора со случайным размером (от 0 до MAX_N-1)
  std::vector<int> numbers(generator() % MAX_N);
  
  // Заполнение вектора случайными числами в диапазоне [MINIMUM, MAXIMUM)
  for (auto &elem : numbers) {
    elem = MINIMUM + generator() % (MAXIMUM - MINIMUM);
  }

  // Вывод исходного массива
  for (auto &elem : numbers) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  // Сортировка массива 
  for (size_t i = 0; i < numbers.size(); ++i) {
    for (size_t j = i + 1; j < numbers.size(); ++j) {
      if (numbers[i] > numbers[j]) {
        std::swap(numbers[i], numbers[j]);  
      }
    }
  }

  // Вывод отсортированного массива
  for (auto &elem : numbers) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}
