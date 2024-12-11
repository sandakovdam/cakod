#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

void dijkstra(int V, vector < vector < Edge >> & adj, int start, int end) {
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    priority_queue < pair<int, int>, vector < pair<int, int>, greater < pair<int, int> > > > pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "Для вершины " << end << " нет пути от начальной вершины.\n";
    }
    else {
        cout << "Кратчайшее расстояние до вершины " << end << ": " << dist[end] << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int V, E;
    cout << "Введите количество вершин и рёбер: ";
    cin >> V >> E;

    vector < vector < Edge >> adj(V);

    cout << "Введите рёбра (формат: вершина_1 вершина_2 вес):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }

    int start, end;
    cout << "Введите начальную вершину: ";
    cin >> start;
    cout << "Введите конечную вершину: ";
    cin >> end;

    dijkstra(V, adj, start, end);

    return 0;
}