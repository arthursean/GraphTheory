## GraphTheory

Alunos: Arthur Sean Cerqueira Campos e Diêgo de Araujo Correia

Algoritmos:

Kosaraju: SCC

Dijsktra: SPP

Prim: AGM

Kruskal: AGM

Bellman-Ford: SPP

# Especificações do algoritmo Bellman-Ford

- Testes:

  As instâncias de entrada estão na pasta /bateriaTestes no diretório do algoritmo, e são do formato bateria1x.mtx, sendo x o índice do teste de 1 a 20.

- Entrada e saída:

  A entrada é a padrão dos algoritmos de caminho mínimo, recebendo a quantidade de vértices e arestas, e logo após as arestas com seus pesos, no formato u, v, w, sendo u o vértice fonte e v o de destino e w o peso.

  * **O algoritmo foi implementado para grafos direcionados.**

  A saída será a distância do vértice escolhido com o parâmetro -i, que por padrão é setado como 1, até todos os vértices do grafo. Para um grafo com ciclo negativo, o programa retorna "O grafo contém um ciclo negativo". Caso um vértice seja inalcansável a partir do escolhido, sua distância será setada como **INT_MAX**, que em c++ é `2147483647`.

  * Exemplos de saída:

    ` 1:0 2:5 3:4 4:2 5:10 6:3 `

    "O grafo contém um ciclo negativo"
