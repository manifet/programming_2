#include <iostream>  
#include <cstdlib>   
#include <cstring>    

// Структура, представляющая студента
struct Student {
    char name[50]; 
    int id;         
};

// Функция сравнения студентов по имени для сортировки
int compareStudentsByName(const void* firstStudentPtr, const void* secondStudentPtr) {
    const Student* firstStudent = (const Student*)firstStudentPtr;
    const Student* secondStudent = (const Student*)secondStudentPtr;

    // Сравнение имён студентов с помощью strcmp
    return strcmp(firstStudent->name, secondStudent->name);
}

int main() {
    // Массив студентов
    Student students[] = {
        {"Anna", 1},
        {"Boris", 2},
        {"Victor", 3},
        {"Dmitry", 4}
    };

    // Определение количества студентов в массиве
    int studentCount = sizeof(students) / sizeof(students[0]);

    // Сортировка массива студентов по имени с помощью qsort
    qsort(students, studentCount, sizeof(Student), compareStudentsByName);

    // Вывод отсортированного списка студентов
    std::cout << "Отсортированный список студентов:" << std::endl;
    for (int i = 0; i < studentCount; ++i) {
        std::cout << students[i].name << " (ID: " << students[i].id << ")" << std::endl;
    }

    return 0;
}
