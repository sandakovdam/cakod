#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX // Значение бесконечности

using namespace std;

// Структура для представления ребра графа
struct Edge {
    int to;
    int weight;
};

// Функция для нахождения кратчайших расстояний от вершины S до всех остальных вершин в графе
void dijkstra(vector<vector<Edge>>& graph, int S, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist.assign(graph.size(), INF);
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m; // Количество вершин и ребер
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Так как граф неориентированный
    }

    int S; // Начальная вершина
    cin >> S;

    vector<int> dist;
    dijkstra(graph, S, dist);

    cout << "Shortest distances from vertex " << S << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
