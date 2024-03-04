#include <bits/stdc++.h>
#define maximum INT_MAX
using namespace std;

vector<pair<int, int>> prim(vector<vector<pair<int, int>>> &adj, int &minimum, int s)
{
    vector<int> dist(adj.size(), maximum);
    vector<int> prev(adj.size(), -1);
    vector<bool> flag(adj.size(), false);
    vector<pair<int, int>> result;
    result = vector<pair<int, int>>();

    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    fila.push(make_pair(dist[s], s));
    while (!fila.empty())
    {
        int v = fila.top().second;
        fila.pop();
        flag[v] = true;
        for (auto test : adj[v])
        {
            int u = test.first;
            int p = test.second;
            if (!flag[u] && dist[u] > p)
            {
                dist[u] = p;
                prev[u] = v;
                fila.push(make_pair(dist[u], u));
            }
        }
    }
    for (unsigned i = 2; i < adj.size(); i++)
    {
        result.push_back(make_pair(i, prev[i]));
        minimum += dist[i];
    }
    return result;
}
int main(int argc, char *argv[])
{
    string outFile = "";
    string inputFile = "";
    bool printSolution = false;
    int n, m, p, v1, v2;
    int s = 1;
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h"))
        {
            cout << "Help:" << endl;
            cout << "-h : mostra o help" << endl;
            cout << "-o <arquivo> : redireciona a saida para o ‘‘arquivo’’" << endl;
            cout << "-f <arquivo> : indica o ‘‘arquivo’’ que contém o grafo de entrada" << endl;
            cout << "-s : mostra a solução" << endl;
            cout << "-i : vértice inicial" << endl;
            return 0;
        }
        if (!strcmp(argv[i], "-o") && i < argc - 1)
        {
            outFile = argv[++i];
            continue;
        }
        if (!strcmp(argv[i], "-i") && i < argc - 1)
        {
            s = atoi(argv[++i]);
            continue;
        }
        if (!strcmp(argv[i], "-f") && i < argc - 1)
        {
            inputFile = argv[++i];
            continue;
        }
        if (!strcmp(argv[i], "-s"))
        {
            printSolution = true;
        }
    }
    ifstream fp(inputFile);
    if (!fp)
    {
        cout << "O arquivo não consegue ser aberto ou não existe" << endl;
        return 0;
    }
    fp >> n >> m;
    n++;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 1; i < n; i++)
    {
        adj[i] = vector<pair<int, int>>();
    }
    for (int i = 0; i < m; i++)
    {
        fp >> v1 >> v2 >> p;
        adj[v1].push_back(make_pair(v2, p));
        adj[v2].push_back(make_pair(v1, p));
    }
    int minimum = 0;
    vector<pair<int, int>> resultado = prim(adj, minimum, s);
    if (!(outFile == ""))
    {
        ofstream fp(outFile);
        if (!fp)
        {
            cout << "Não foi possível abrir o arquivo de saída: " << outFile << endl;
        }
        else
        {
            if (printSolution)
            {
                for (int i = 1; i < n; i++)
                {
                    fp << "(" << resultado[i].second << "," << resultado[i].first << ") ";
                }
            }
            else
            {
                fp << minimum;
            }
            fp << endl;
            fp.close();
        }
    }
    if (printSolution)
    {
        for (int i = 1; i < n; i++)
        {
            cout << "(" << resultado[i].second << "," << resultado[i].first << ")"
                 << " ";
        }
    }
    else
    {
        cout << minimum;
    }
    cout << endl;
}