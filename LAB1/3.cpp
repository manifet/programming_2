#include <cstddef> 
#include <iostream>   
#include <utility>  
#include <vector>    
#include <string>   
#include <regex>    

// Функция проверки соответствия номера формату XX-XX-XX
bool is_correct_phone_number(std::string &str) {
  std::regex reg(R"(\d{2}-\d{2}-\d{2})"); // Регулярное выражение для формата
  return std::regex_match(str, reg);      // Проверка полного соответствия
}

int main() {
  // Запрос количества телефонных номеров
  size_t count;
  std::cout << "Кол-во номеров: ";
  std::cin >> count;
  
  // Создание вектора для хранения номеров
  std::vector<std::string> phones(count);
  
  // Ввод номеров с проверкой формата
  for (auto &elem : phones) {
    std::cout << "Введите номер телефона в форматике XX-XX-XX: ";
    std::cin >> elem;
    if (!is_correct_phone_number(elem)) {
      std::cerr << "Некорректный номер телефона.\n"; 
      exit(-1); 
    }    
  }
  
  // Сортировка номеров по возрастанию 
  for (size_t i = 0; i < count; ++i) {
    for (size_t j = i + 1; j < count; ++j) {
      if (phones[i] > phones[j]) {
        std::swap(phones[i], phones[j]); 
      }
    }   
  }

  // Вывод отсортированных номеров
  for (auto &elem : phones) {
    std::cout << elem << '\n';
  }
}
