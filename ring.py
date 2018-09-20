# simulation of a particle walking on a circular graph

import numpy as np
import matplotlib.pyplot as plt

def nxt(n,size):
    p = np.random.rand()
    if p < .5:
        nx = n-1
        if n==0:
            nx = size-1
    else:
        nx = n+1
        if n==(size-1):
            nx = 0

    return nx


N = 100000
ring_size = 11
tot_visited = np.zeros(ring_size)

for count in range(N):
    visited = np.zeros(ring_size)
    n = 0 # 0 is the initial node
    last = n
    while sum(visited) < len(visited):
        if visited[n] == 0:
            last = n
            visited[n] = 1
        n = nxt(n,ring_size)
    tot_visited[last] += 1

print("Probabilities of each node being visited last:",tot_visited/N)
nodes = np.arange(0,ring_size,1)
plt.plot(nodes,tot_visited/N)
plt.show()
