#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define maximum INT_MAX
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int s)
{
    vector<int> dist(adj.size(), maximum);
    vector<int> prev(adj.size(), -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    fila.push(make_pair(s, 0));
    dist[s] = 0;
    while (!fila.empty())
    {
        int v = fila.top().first;
        fila.pop();
        for (int i = 0; i < adj[v].size(); i++)
        {
            int p = adj[v][i].second;
            int u = adj[v][i].first;
            if (dist[u] > dist[v] + p)
            {
                dist[u] = dist[v] + p;
                fila.push(make_pair(u, dist[u]));
            }
        }
    }
    return dist;
}
int main()
{
    int n, m, p, v1, v2, s;
    cin >> n >> m;
    n++;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 1; i < n; i++)
    {
        adj[i] = vector<pair<int, int>>();
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> p;
        adj[v1].push_back(make_pair(v2, p));
        adj[v2].push_back(make_pair(v1, p));
    }
    cin >> s;
    vector<int> dist(n);
    dist = dijkstra(adj, 1);
    for (int i = 1; i < n; i++)
    {
        cout << i << ":" << dist[i] << " ";
    }
    cout << endl;
}