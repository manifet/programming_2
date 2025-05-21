#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Определяем значение бесконечности (для отсутствующих путей)

int main() {
    int N, S, F;
    cin >> N >> S >> F; // Ввод количества вершин и номеров начальной и конечной вершин
    S--; F--; // Преобразуем номера вершин в индексацию с нуля

    // Считываем матрицу смежности графа
    vector<vector<int>> adj(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] == -1) adj[i][j] = INF; // -1 обозначает отсутствие ребра
        }

    // Инициализация расстояний и массива посещений
    vector<int> dist(N, INF); // Массив кратчайших расстояний
    vector<bool> visited(N, false); // Массив флагов посещённых вершин
    dist[S] = 0; // Расстояние от начальной вершины до себя = 0

    // Алгоритм Дейкстры
    for (int i = 0; i < N; ++i) {
        int v = -1;
        // Выбираем непосещённую вершину с минимальным расстоянием
        for (int j = 0; j < N; ++j)
            if (!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        if (dist[v] == INF) break; // Если остались только недостижимые вершины — завершаем

        visited[v] = true; // Помечаем вершину как посещённую

        // Обновляем расстояния до соседей
        for (int u = 0; u < N; ++u) {
            if (adj[v][u] != INF) {
                dist[u] = min(dist[u], dist[v] + adj[v][u]);
            }
        }
    }

    // Вывод результата: если путь есть — выводим длину, иначе -1
    if (dist[F] == INF)
        cout << -1 << endl;
    else
        cout << dist[F] << endl;

    return 0;
}


// 4 1 4
// 0 5 -1 10
// 5 0 3 -1
// -1 3 0 1
// 10 -1 1 0

// 9