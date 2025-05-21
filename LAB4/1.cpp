#include <iostream>    
#include <fstream>   
#include <unordered_set>  
#include <vector>      
#include <algorithm>    

int main() {
    std::ifstream input("input.txt");  
    std::ofstream output("output.txt"); 

    std::unordered_set<int> positiveNumbers; // Множество для хранения уникальных положительных чисел
    int value;

    // Чтение значений из файла
    while (input >> value) {
        if (value > 0) {
            // Если число положительное — добавляем его во множество
            positiveNumbers.insert(value);
        } else if (value < 0) {
            // Если число отрицательное — удаляем из множества его противоположность
            positiveNumbers.erase(-value);
        } else {
            // Если число 0 — завершаем ввод и выводим текущие положительные числа
            std::vector<int> sortedValues(positiveNumbers.begin(), positiveNumbers.end());
            std::sort(sortedValues.begin(), sortedValues.end()); // Сортировка по возрастанию

            for (int number : sortedValues) {
                output << number << " "; // Запись отсортированных чисел в файл
            }
            output << std::endl;
            break; 
        }
    }

    input.close(); 
    output.close(); 
    return 0;
}
