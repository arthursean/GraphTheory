#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
    int size;
    int *parent;
    int *rank;

    UnionFind(int n)
    {
        this->size = n;
        this->parent = new int[size + 1];
        this->rank = new int[size + 1];
    }

    ~UnionFind()
    {
        delete[] parent;
        delete[] rank;
    }

    void makeSet(int x)
    {
        this->parent[x] = x;
        this->rank[x] = 0;
    }

    int find(int x)
    {
        if (this->parent[x] != x)
        {
            return find(this->parent[x]);
        }
        else
            return x;
    }

    void unify(int x, int y)
    {
        if (this->parent[x] >= this->parent[y])
        {
            this->parent[y] = x;
            if (this->parent[x] == this->parent[y])
            {
                this->rank[x] += 1;
            }
        }
        else
        {
            this->parent[x] = y;
        }
    }
};

struct Comparator
{
    bool operator()(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) const
    {
        return a.second < b.second;
    }
};

vector<pair<int, int>> kruskal(vector<pair<pair<int, int>, int>> &E, int n, int &sum)
{
    UnionFind sets(n);

    vector<pair<int, int>> AGM;

    for (int i = 1; i <= n; i++)
    {
        sets.makeSet(i);
    }

    sort(E.begin(), E.end(), Comparator());

    for (auto &e : E)
    {
        if (sets.find(e.first.first) != sets.find(e.first.second))
        {
            sets.unify(e.first.first, e.first.second);
            AGM.push_back({e.first.first, e.first.second});
            sum += e.second;
        }
    }
    return AGM;
}

int main(int argc, char *argv[])
{
    string outFile = "";
    string inputFile = "";
    bool printSolution = false;

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h"))
        {
            cout << "Help:" << endl;
            cout << "-h : mostra o help" << endl;
            cout << "-o <arquivo> : redireciona a saida para o ‘‘arquivo’’" << endl;
            cout << "-f <arquivo> : indica o ‘‘arquivo’’ que contém o grafo de entrada" << endl;
            cout << "-s : mostra a solução" << endl;
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

    int n, m;
    fp >> n >> m;

    vector<pair<pair<int, int>, int>> E(m);
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        fp >> v >> u >> w;
        E.push_back({{v, u}, w});
    }
    fp.close();

    vector<pair<int, int>> AGM = kruskal(E, n, sum);

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
                for (int i = 0; i < n - 1; i++)
                {
                    fp << "(" << AGM[i].first << "," << AGM[i].second << ")"
                       << " ";
                }
            }
            else
            {
                fp << sum;
            }
            fp << endl;
            fp.close();
        }
    }
    if (printSolution)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << "(" << AGM[i].first << "," << AGM[i].second << ")"
                 << " ";
        }
    }
    else
    {
        cout << sum;
    }
    cout << endl;
    return 0;
}