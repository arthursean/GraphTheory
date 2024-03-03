#include <bits/stdc++.h>
#define maximum INT_MAX
using namespace std;

vector<int> bellman(vector<vector<pair<int, int>>> &adj, int s)
{
    vector<int> dist(adj.size(), maximum);
    vector<int> prev(adj.size(), -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    return dist;
}
int main(int argc, char *argv[])
{
    string outFile = "";
    string inputFile = "";
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
    }
    if (inputFile == "")
    {
        cout << "Nenhum arquivo de entrada escolhido. Use '-f' para escolher o arquivo" << endl;
        return 0;
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
    fp.close();
    vector<int> dist = bellman(adj, s);
    if (!(outFile == ""))
    {
        ofstream fp(outFile);
        if (!fp)
        {
            cout << "Não foi possível abrir o arquivo de saída: " << outFile << endl;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (dist[i] == maximum)
                {
                    dist[i] = -1;
                }
                fp << i << ":" << dist[i] << " ";
            }
            fp << endl;
            fp.close();
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (dist[i] == maximum)
        {
            dist[i] = -1;
        }
        cout << i << ":" << dist[i] << " ";
    }
    cout << endl;
}