#include <iostream>
#include <vector>
#include <algorithm>

// Структура, описывающая лекцию (начало и конец)
struct Lecture {
    int start;
    int end;
};

// Функция сравнения для сортировки лекций по времени окончания
bool compareLectures(const Lecture& a, const Lecture& b) {
    return a.end < b.end;
}

int main() {
    int N;
    std::cin >> N; // Ввод количества лекций

    std::vector<Lecture> lectures(N); // Массив лекций

    // Ввод начала и конца каждой лекции
    for (int i = 0; i < N; ++i) {
        std::cin >> lectures[i].start >> lectures[i].end;
    }

    // Сортируем лекции по времени окончания (жадный подход)
    std::sort(lectures.begin(), lectures.end(), compareLectures);

    int count = 0;        // Количество выбранных лекций
    int lastEndTime = 0;  // Время окончания последней выбранной лекции

    // Проходим по отсортированным лекциям
    for (const auto& lecture : lectures) {
        // Если текущая лекция не пересекается с предыдущей выбранной
        if (lecture.start >= lastEndTime) {
            ++count;                  // Выбираем её
            lastEndTime = lecture.end; // Обновляем последнее время окончания
        }
    }

    std::cout << count << std::endl; // Выводим результат — максимум непересекающихся лекций
    return 0;
}


// 3
// 1 4
// 2 3
// 3 5

// 2
