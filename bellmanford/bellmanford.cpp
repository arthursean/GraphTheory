#include <bits/stdc++.h>

using namespace std;

bool bellman_ford(vector<vector<int>>& G, int s, int n, vector<int> & dist) { 
    dist[s] = 0; 

    for (int i = 1; i < n; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                int w = G[u][v];
                if (w != INT_MAX && dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int w = G[u][v];
            if (w != INT_MAX && dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    string outFile = "";
    string inputFile = "";
    int s = 1; 
    for (int i = 1; i < argc; i++){
        if (!strcmp(argv[i], "-h")){
            cout << "Help:" << endl;
            cout << "-h : mostra o help" << endl;
            cout << "-o <arquivo> : redireciona a saida para o ‘‘arquivo’’" << endl;
            cout << "-f <arquivo> : indica o ‘‘arquivo’’ que contém o grafo de entrada" << endl;
            cout << "-i : vértice inicial" << endl;
            return 0;
        }
        if (!strcmp(argv[i], "-o") && i < argc - 1){
            outFile = argv[++i];
            continue;
        }
        if (!strcmp(argv[i], "-i") && i < argc - 1){
            s = atoi(argv[++i]);
            continue;
        }
        if (!strcmp(argv[i], "-f") && i < argc - 1){
            inputFile = argv[++i];
            continue;
        }
    }
    if (inputFile == ""){
        cout << "Nenhum arquivo de entrada escolhido. Use '-f' para escolher o arquivo" << endl;
        return 0;
    }
    ifstream fp(inputFile);
    if (!fp){
        cout << "O arquivo não consegue ser aberto ou não existe" << endl;
        return 0;
    }

    int n, m;
    fp >> n >> m;

    vector<vector<int>> G(n + 1, vector<int>(n + 1, INT_MAX)); 
    vector<int> dist(n + 1, INT_MAX);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        fp >> u >> v >> w; 
        G[u][v] = w; 
    }

    fp.close();

    bool is_not_a_negative_circuit = bellman_ford(G, s, n, dist); 
    
    if (!(outFile == "")){
        ofstream fp(outFile);
        if (!fp){
            cout << "Não foi possível abrir o arquivo de saída: " << outFile << endl;
        }
        else {
            if (is_not_a_negative_circuit){
                for (int i = 1; i <= n; i++){
                    cout << i << ":" << dist[i] << " ";
                }
            } else {
                cout << "O grafo contém um ciclo negativo";
            }
            fp << endl;
            fp.close();
        }
    }
    if (is_not_a_negative_circuit){
        for (int i = 1; i <= n; i++){
            cout << i << ":" << dist[i] << " ";
        }
    } else {
        cout << "O grafo contém um ciclo negativo";
    }
    cout << endl;
    return 0;
}
