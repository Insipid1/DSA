#  Dijkstra’s Algorithm (Adjacency Matrix) in C

## (a) Data structure definition
This program uses an **adjacency matrix** to store edge weights:

- `int graph[MAX][MAX]`
- `graph[i][j] = 0` means **no edge**
- `graph[i][j] > 0` means there is an edge with that weight

It also uses:
- `int dist[MAX]` — shortest distance from `source` to each vertex
- `int visited[MAX]` — marks whether a vertex is finalized (processed)

##  Functions implemented
### `int minDistance(int dist[], int visited[], int n)`
- **Purpose:** Return the index of the unvisited vertex with the smallest `dist`.

### `void dijkstra(int graph[MAX][MAX], int n, int source)`
- **Purpose:** Compute shortest distances from `source` to all vertices.

### `void printResult(int dist[], int n)`
- **Purpose:** Display final shortest distances in a readable format.

## (c) `main()` organization overview
Typical `main()` flow:
1. Read number of vertices `n`.
2. Read the adjacency matrix.
3. Read the source vertex.
4. Call `dijkstra(graph, n, source)`.
5. Print the shortest distances.

## (d) Sample output (complete run)
```text
Enter number of vertices: 4
Enter adjacency matrix (0 = no edge):
0 1 4 0
1 0 2 9
4 2 0 2
0 9 3 0
Enter source vertex: 0

Vertex   Distance from Source
0        0
1        1
2        2
3        9
```