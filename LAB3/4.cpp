#include <iostream>
#include <cstdlib>
#include <cstring>

struct Student {
    char name[50];
    int id;
};

int compareStudentsByName(const void* firstStudentPtr, const void* secondStudentPtr) {
    const Student* firstStudent = (const Student*)firstStudentPtr;
    const Student* secondStudent = (const Student*)secondStudentPtr;

    return strcmp(firstStudent->name, secondStudent->name);
}

int main() {
    Student students[] = {
        {"Anna", 1},
        {"Boris", 2},
        {"Victor", 3},
        {"Dmitry", 4}
    };

    int studentCount = sizeof(students) / sizeof(students[0]);

    qsort(students, studentCount, sizeof(Student), compareStudentsByName);

    std::cout << "Отсортированный список студентов:" << std::endl;
    for (int i = 0; i < studentCount; ++i) {
        std::cout << students[i].name << " (ID: " << students[i].id << ")" << std::endl;
    }

    return 0;
}