import util

# Definição do Grafo

class Graph(object):
    # Initialize the matrix
    def __init__(self, size):
        self.adjMatrix = []
        for i in range(size):
            self.adjMatrix.append([INF for i in range(size)])
            self.adjMatrix[i][i] = 0
        self.size = size
    
    # Add edges
    def add_edge(self, v1, v2, w): # Onde w é o peso (weight)
        if v1 == v2:
            print("Same vertex %d and %d" % (v1, v2))
        self.adjMatrix[v1][v2] = int(w * 100)/100
        
    # Remove edges
    def remove_edge(self, v1, v2):
        if self.adjMatrix[v1][v2] == 0:
            print("No edge between %d and %d" % (v1, v2))
            return
        self.adjMatrix[v1][v2] = 0
        self.adjMatrix[v2][v1] = 0
    
    def __len__(self):
        return self.size
    
    # Print the matrix
    def print_matrix(self):
        for row in self.adjMatrix:
            for val in row:
#                print('{:4}'.format(val))
                print('{:4}'.format(val), end='')
            print()
    
    # Return the matrix:
    def return_matrix(self):
        return self.adjMatrix

# Algoritmo

def floydWarshall(graph, n_nodes):

    dist = list(map(lambda i: list(map(lambda j: j, i)), graph))

    for k in range(n_nodes):

        # pick all vertices as source one by one
        for i in range(n_nodes):

            # Pick all vertices as destination for the
            # above picked source
            for j in range(n_nodes):

                # If vertex k is on the shortest path from
                # i to j, then update the value of dist[i][j]
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    
    return dist


# Excentricidade de um grafo:
    # Retorna uma lista com a excentricidade de cada vértice.

def excentricidade(matriz_min_dist):
    
    n_nodes = len(matriz_min_dist)
    exct = [INF for i in range(n_nodes)] # Excentricidade de cada vértice

    for i in range(n_nodes):
        l = []
        for j in range(n_nodes):
            l.append(matriz_min_dist[j][i])
        exct[i] = max(l)

    return exct


INF = util.infinito()
