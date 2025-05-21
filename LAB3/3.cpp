#include <iostream>  
#include <vector>    
#include <cstdlib>
#include <ctime>  

using namespace std;

// Функция быстрой сортировки матрицы по первому столбцу
void sortByFirstColumn(vector<vector<int>>& matrix, int start, int end) {
    if (start < end) {
        int pivotValue = matrix[end][0];  // Опорное значение — элемент первого столбца последней строки
        int partitionIndex = start - 1;   // Индекс, отделяющий меньшие элементы от больших

        // Переставляем строки так, чтобы строки с меньшим значением в первом столбце оказались слева от опорного
        for (int current = start; current < end; current++) {
            if (matrix[current][0] < pivotValue) {
                partitionIndex++;
                swap(matrix[partitionIndex], matrix[current]);
            }
        }

        // Ставим опорную строку на своё место
        swap(matrix[partitionIndex + 1], matrix[end]);
        int pivotIndex = partitionIndex + 1;

        // Рекурсивная сортировка левой и правой части матрицы
        sortByFirstColumn(matrix, start, pivotIndex - 1);
        sortByFirstColumn(matrix, pivotIndex + 1, end);
    }
}

int main() {
    const int ROWS = 10; // Количество строк в матрице
    const int COLS = 5;  // Количество столбцов в матрице
    vector<vector<int>> matrix(ROWS, vector<int>(COLS)); // Создание матрицы 10x5

    srand(time(0)); // Инициализация генератора случайных чисел

    // Заполнение матрицы случайными числами от 5 до 61
    for (auto& row : matrix) {
        for (auto& element : row) {
            element = rand() % 57 + 5;
        }
    }

    // Вывод изначальной матрицы
    cout << "Изначальная матрица:\n";
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    // Сортировка матрицы по значениям в первом столбце
    sortByFirstColumn(matrix, 0, ROWS - 1);

    // Вывод отсортированной матрицы
    cout << "\nСортированная матрица по столбцу:\n";
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
