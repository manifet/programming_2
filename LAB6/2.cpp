#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int cost;
};

int dijkstra(int N, const vector<int>& fuelCosts, const vector<vector<Edge>>& graph) {
    vector<int> dist(N, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[0] = 0;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int newDist = currentDist + fuelCosts[u];

            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({ newDist, v });
            }
        }
    }

    return (dist[N - 1] == INT_MAX) ? -1 : dist[N - 1];
}

int main() {
    int N;
    cin >> N;
    vector<int> fuelCosts(N);
    for (int i = 0; i < N; ++i) {
        cin >> fuelCosts[i];
    }

    int M;
    cin >> M;
    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[u].push_back({ v, fuelCosts[u] });
        graph[v].push_back({ u, fuelCosts[v] });
    }

    int result = dijkstra(N, fuelCosts, graph);
    cout << result << endl;

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
