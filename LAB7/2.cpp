#include <iostream>
#include <vector>
#include <algorithm>

// Структура, представляющая коробку с весом и грузоподъёмностью
struct Box {
    int weight;    // Вес коробки
    int capacity;  // Максимальная нагрузка, которую коробка может выдержать
};

// Сортируем коробки по убыванию грузоподъёмности (чтобы более надёжные рассматривать первыми)
bool compareBoxes(const Box& a, const Box& b) {
    return a.capacity > b.capacity;
}

int main() {
    int n;
    std::cin >> n; // Ввод количества коробок

    std::vector<Box> boxes(n);

    // Ввод характеристик каждой коробки
    for (int i = 0; i < n; ++i) {
        std::cin >> boxes[i].weight >> boxes[i].capacity;
    }

    // Сортируем коробки по убыванию грузоподъёмности (жадный подход)
    std::sort(boxes.begin(), boxes.end(), compareBoxes);

    int maxBoxes = 0;       // Максимальное количество выбранных коробок
    int currentWeight = 0;  // Общий вес уже выбранных коробок

    // Перебираем коробки
    for (const auto& box : boxes) {
        // Если текущая коробка выдержит весь вес предыдущих, добавляем её
        if (currentWeight <= box.capacity) {
            currentWeight += box.weight; // Увеличиваем общий вес
            maxBoxes++;                  // Увеличиваем счётчик выбранных коробок
        }
    }

    std::cout << maxBoxes << std::endl; // Выводим результат
    return 0;
}


// 5
// 3 10
// 2 5
// 1 8
// 4 12
// 2 7

// 4

