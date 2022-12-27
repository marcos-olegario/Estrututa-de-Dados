import math

# Euclidian Distance

def Dist(p, q):
    dist = math.sqrt((p[0] - q[0])**2 + (p[1] - q[1])**2)
    return dist


def infinito():
	return 9999

def print_coord(lista):
    print(str(lista[0]) + "," + str(lista[1]))