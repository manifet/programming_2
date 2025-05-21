#include <iostream>

// Рекурсивная функция для вывода чисел от A до B включительно
void print_segment(int a, int b) {

  std::cout << a << ' ';
  

  if (a != b) {
    // Рекурсивный вызов с шагом +1 или -1 в зависимости от направления
    print_segment(a + ((a > b) ? -1 : 1), b);
  }
}

int main() {
  int a, b;
  
  std::cout << "Введите A: ";
  std::cin >> a;
  std::cout << "Введите B: ";
  std::cin >> b;

  print_segment(a, b);
}