#include <iostream>
#include <vector>
#include <random>

int main() {
  std::random_device rd;       
  std::mt19937 generator(rd()); // Генератор 
  
  // Константы для настройки генерации
  const size_t MAX_N = 20;     // Максимально возможный размер вектора
  const size_t MINIMUM = 0;    // Минимальное значение элемента 
  const size_t MAXIMUM = 100;  // Максимальное значение элемента

  // Создание вектора со случайным размером (от 0 до MAX_N-1 элементов)
  std::vector<int> numbers(generator() % MAX_N);
  
  // Заполнение вектора случайными числами в диапазоне [MINIMUM, MAXIMUM-1]
  for (auto &elem : numbers) {
    elem = MINIMUM + generator() % (MAXIMUM - MINIMUM);
  }

  // Вывод исходного массива
  for (auto &elem : numbers) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';  // Переход на новую строку после вывода

  // Сортировка массива по убыванию 
  for (size_t i = 0; i < numbers.size(); ++i) {
    for (size_t j = i + 1; j < numbers.size(); ++j) {
      if (numbers[i] < numbers[j]) {  
        std::swap(numbers[i], numbers[j]); 
      }
    }
  }

  // Вывод отсортированного по убыванию массива
  for (auto &elem : numbers) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';  
}