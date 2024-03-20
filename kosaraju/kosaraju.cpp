#include <bits/stdc++.h>
#define maximum INT_MAX
using namespace std;

void postOrderDfs(vector<vector<int>> &adj, vector<bool> &flag, stack<int> &pilha, int vert)
{
    flag[vert] = true;
    for (int i = 0; i < adj[vert].size(); i++)
    {
        if (!flag[adj[vert][i]])
        {
            postOrderDfs(adj, flag, pilha, adj[vert][i]);
        }
    }
    pilha.push(vert);
}
void dfs(vector<vector<int>> &adj, vector<bool> &flag, vector<int> &component, int vert)
{
    flag[vert] = true;
    component.push_back(vert);
    for (int i = 0; i < adj[vert].size(); i++)
    {
        if (!flag[adj[vert][i]])
        {
            dfs(adj, flag, component, adj[vert][i]);
        }
    }
}
vector<vector<int>> kosaraju(vector<vector<int>> &adj, int n)
{
    vector<vector<int>> reverseAdj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            reverseAdj[adj[i][j]].push_back(i);
        }
    }
    stack<int> pilha;
    vector<bool> flag(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!flag[i])
        {
            postOrderDfs(reverseAdj, flag, pilha, i);
        }
    }
    fill(flag.begin(), flag.end(), false);
    vector<vector<int>> stronglyConnectedComponents;
    while (!pilha.empty())
    {
        int v = pilha.top();
        pilha.pop();
        if (!flag[v])
        {
            vector<int> component;
            dfs(adj, flag, component, v);
            stronglyConnectedComponents.push_back(component);
        }
    }
    return stronglyConnectedComponents;
}
int main(int argc, char *argv[])
{
    string outFile = "";
    string inputFile = "";
    int n, m, v1, v2;
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h"))
        {
            cout << "Help:" << endl;
            cout << "-h : mostra o help" << endl;
            cout << "-o <arquivo> : redireciona a saida para o ‘‘arquivo’’" << endl;
            cout << "-f <arquivo> : indica o ‘‘arquivo’’ que contém o grafo de entrada" << endl;
            return 0;
        }
        if (!strcmp(argv[i], "-o") && i < argc - 1)
        {
            outFile = argv[++i];
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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i] = vector<int>();
    }
    for (int i = 0; i < m; i++)
    {
        fp >> v1 >> v2;
        adj[v1 - 1].push_back(v2 - 1);
    }
    fp.close();
    vector<vector<int>> stronglyConnectedComponents = kosaraju(adj, n);
    if (!(outFile == ""))
    {
        ofstream fp(outFile);
        if (!fp)
        {
            cout << "Não foi possível abrir o arquivo de saída: " << outFile << endl;
        }
        else
        {
            for (int i = 0; i < stronglyConnectedComponents.size(); i++)
            {
                for (int j = 0; j < stronglyConnectedComponents[i].size(); j++)
                {
                    fp << stronglyConnectedComponents[i][j] + 1 << " ";
                }
                fp << endl;
            }
        }
    }
    for (int i = 0; i < stronglyConnectedComponents.size(); i++)
    {
        for (int j = 0; j < stronglyConnectedComponents[i].size(); j++)
        {
            cout << stronglyConnectedComponents[i][j] + 1 << " ";
        }
        cout << endl;
    }
}