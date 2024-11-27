#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(vector<vector<int>> w, int st, int n)
{
      
    bool visited[6]; //массив посещенных вершин графа
    int D[6]; //массив длин кратчайщих маршрутов

    for (int i = 0; i < 2; i++)
    {
        D[i] = w[st][i];
        visited[i] = false;

    }
    D[st] = 0; //стартовая вершина
    int index = 0, u = 0;
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && D[j] < min)
            {
                min = D[j];
                index = j;
            }
        }
        u = index;
        visited[u] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && w[u][j] != INT_MAX && D[u] != INT_MAX && (D[u] + w[u][j] < D[j]))
            {
                D[j] = D[u] + w[u][j];
            }
        }
    }
    cout << "Стоимость пути из начальной вершины до остальных(Алгоритм Дейкстры):\t\n";
    for (int i = 0; i < n; i++)
    {
        if (D[i] != INT_MAX)
            cout << st << " -> " << i << " = " << D[i] << endl;
        else
            cout << st << " -> " << i << " = " << "маршрут недоступен" << endl;
    }
}

int main() {
    int n = 6;
    vector<vector<int>> w; //граф
    w.resize(n); //размер N
    for (int i = 0; i < n; i++) {
        w[i].resize(n);
    }
    w[0][1] = 7;
    w[1][0] = 7;
    w[0][2] = 9;
    w[2][0] = 9;
    w[0][5] = 14;
    w[5][0] = 14;
    w[1][2] = 10;
    w[2][1] = 10;
    w[1][3] = 15;
    w[3][1] = 15;
    w[2][3] = 11;
    w[3][2] = 11;
    w[2][5] = 2;
    w[5][2] = 2;
    w[3][4] = 6;
    w[4][3] = 6;
    w[4][5] = 9;
    w[5][4] = 9;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << w[i][j] << "\t";
        }
        cout << endl;
    }
    Dijkstra(w, 0, n);
    cout << INT_MAX;
    return 0;
}
