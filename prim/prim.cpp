#include <bits/stdc++.h>
#define maximum INT_MAX
using namespace std;

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
    fp.close();
}