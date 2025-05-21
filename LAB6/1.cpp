#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int N, S, F;
    cin >> N >> S >> F;
    S--; F--; 

    vector<vector<int>> adj(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] == -1) adj[i][j] = INF;
        }

    vector<int> dist(N, INF);
    vector<bool> visited(N, false);
    dist[S] = 0;

    for (int i = 0; i < N; ++i) {
        int v = -1;
        for (int j = 0; j < N; ++j)
            if (!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        if (dist[v] == INF) break;

        visited[v] = true;

        for (int u = 0; u < N; ++u) {
            if (adj[v][u] != INF) {
                dist[u] = min(dist[u], dist[v] + adj[v][u]);
            }
        }
    }

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