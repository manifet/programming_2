#include <cstdint>  
#include <iostream>

// Рекурсивная функция вывода простых делителей числа
void print_prime_divs(uint32_t n, uint32_t div, bool print_current_div) {

  if (n == 1) {
    return;
  }
  
  // Если делитель превысил √n, значит оставшееся n простое
  if (div * div > n) {
    std::cout << n << ' ';
    return;
  }

  // Если div делит n
  if (n % div == 0) {
    // Выводим делитель только если это первое его вхождение
    if (print_current_div) {
      std::cout << div << ' ';
    }
    print_prime_divs(n / div, div, false);
  } else {
    // Переходим к следующему делителю
    print_prime_divs(n, div + 1, true);
  }
}

int main() {
  uint32_t n;
  std::cout << "Введите n: ";
  std::cin >> n;
  
  print_prime_divs(n, 2, true);
  
  return 0;
}