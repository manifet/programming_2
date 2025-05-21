#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Структура ребра, указывающая на соседнюю вершину и стоимость (не используется в расчётах напрямую)
struct Edge {
    int to;   // Номер вершины, в которую ведёт ребро
    int cost; // Стоимость (не используется в алгоритме, т.к. вместо неё используется fuelCosts)
};

// Реализация алгоритма Дейкстры
int dijkstra(int N, const vector<int>& fuelCosts, const vector<vector<Edge>>& graph) {
    vector<int> dist(N, INT_MAX); // Инициализация расстояний до всех вершин как бесконечность
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Очередь с приоритетом: {стоимость, вершина}

    dist[0] = 0; // Расстояние от начальной вершины (0) до неё самой — 0
    pq.push({ 0, 0 }); // Добавляем начальную вершину в очередь

    while (!pq.empty()) {
        int u = pq.top().second;        // Текущая вершина
        int currentDist = pq.top().first; // Текущая минимальная стоимость пути
        pq.pop();

        if (currentDist > dist[u]) continue; // Если уже есть более короткий путь, пропускаем

        // Проходим по всем соседям текущей вершины
        for (const Edge& edge : graph[u]) {
            int v = edge.to; // Соседняя вершина
            int newDist = currentDist + fuelCosts[u]; // Стоимость переезда = текущая + стоимость топлива на вершине u

            // Если найден более короткий путь — обновляем расстояние
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({ newDist, v });
            }
        }
    }

    // Если конечная вершина недостижима — возвращаем -1, иначе — минимальную стоимость
    return (dist[N - 1] == INT_MAX) ? -1 : dist[N - 1];
}

int main() {
    int N;
    cin >> N; // Ввод количества вершин

    vector<int> fuelCosts(N); // Вектор стоимости топлива на каждой вершине
    for (int i = 0; i < N; ++i) {
        cin >> fuelCosts[i]; // Ввод стоимости топлива для i-й вершины
    }

    int M;
    cin >> M; // Ввод количества рёбер

    vector<vector<Edge>> graph(N); // Список смежности для графа
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v; // Ввод ребра между вершинами u и v
        --u; --v; // Переход к индексации с нуля

        // Добавляем ребро в обе стороны, стоимость берётся по вершине, из которой выезжаем
        graph[u].push_back({ v, fuelCosts[u] });
        graph[v].push_back({ u, fuelCosts[v] });
    }

    int result = dijkstra(N, fuelCosts, graph); // Вызываем алгоритм Дейкстры
    cout << result << endl; // Выводим результат: минимальная стоимость или -1

    return 0;
}



// 4
// 5 10 3 1
// 4
// 1 2
// 2 3
// 3 4
// 1 4

// 9
