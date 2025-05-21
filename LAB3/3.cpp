#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortByFirstColumn(vector<vector<int>>& matrix, int start, int end) {
    if (start < end) {
        int pivotValue = matrix[end][0];
        int partitionIndex = start - 1;

        for (int current = start; current < end; current++) {
            if (matrix[current][0] < pivotValue) {
                partitionIndex++;
                swap(matrix[partitionIndex], matrix[current]);
            }
        }
        
        swap(matrix[partitionIndex + 1], matrix[end]);
        int pivotIndex = partitionIndex + 1;

        sortByFirstColumn(matrix, start, pivotIndex - 1);
        sortByFirstColumn(matrix, pivotIndex + 1, end);
    }
}

int main() {
    const int ROWS = 10;
    const int COLS = 5;
    vector<vector<int>> matrix(ROWS, vector<int>(COLS));

    srand(time(0));

 
    for (auto& row : matrix) {
        for (auto& element : row) {
            element = rand() % 57 + 5;
        }
    }

    cout << "Изначальная матрица:\n";
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    sortByFirstColumn(matrix, 0, ROWS - 1);

    cout << "\nСортированная матрица по столбцу:\n";
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}