import grafo
import util

INF = util.infinito()

# Input e criação do grafo:

n_nodes = int(input())
nodes = []

G = grafo.Graph(n_nodes)

for i in range(n_nodes):
	nodes.append([int(x) for x in input().split(",")])

n_edges = int(input())

for i in range(n_edges):
    p, q = input().split(":")
    weight = util.Dist([int(x) for x in p.split(",")], [int(x) for x in q.split(",")])

    G.add_edge(nodes.index([int(x) for x in p.split(",")]), nodes.index([int(x) for x in q.split(",")]), weight)


# Determinação do vértice mais central:
	# Vértice de menor excentricidade

gph = G.return_matrix()

matriz_min_dist = grafo.floydWarshall(gph, n_nodes)

exct = grafo.excentricidade(matriz_min_dist)

v_mais_central = nodes[exct.index(min(exct))]


# Determinação do vértice mais periférico:
	# Basta ver qual o vértice de maior excentricidade

v_mais_periferico = nodes[exct.index(max(exct))]


# Determinação do vértice mais distante do mais periférico:

l = []
for i in range(n_nodes):
    l.append(matriz_min_dist[i][nodes.index(v_mais_periferico)])

v_mais_distante = nodes[l.index(max(l))]


# Outputs:

util.print_coord(v_mais_central)
util.print_coord(v_mais_periferico)
util.print_coord(v_mais_distante)

