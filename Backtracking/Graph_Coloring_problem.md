# Graph Coloring problem

Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints.
Vertex coloring is the most common graph coloring problem. The problem is, given m colors, find a way of coloring the vertices of a graph such that no two adjacent vertices are colored using same color.

- Graph represented by its adjacency matrix.
- Colors are represented by the integers 1,2,...,m.

Time Complexity: O(m^V)
Space Complexity: O(V)

where V = number of vertices and m= maximum possible colors
And m is the maximum possible color that can be assigned in the Graph.

### Input format

- Number of vertices and edges of the graph
- First and second terminal of each end

### Output format

- printing all the coloring possibilities in the graph

### Example Input

Number of vertices= 4
Number of edges= 4

Adjacency matrix:

	0	1	0	1
	1	0	1	0
	0	1	0	1
	1	0	1	0

### Example Output

Enter number of vertices: 4

Enter number of edges: 4

The maximum possible colours that can be assigned is 3

Enter the first terminal vertex of edge 1: 1

Enter the second terminal vertex of edge 1: 2

Enter the first terminal vertex of edge 2: 2

Enter the second terminal vertex of edge 2: 3

Enter the first terminal vertex of edge 3: 3

Enter the second terminal vertex of edge 3: 4

Enter the first terminal vertex of edge 4: 1

Enter the second terminal vertex of edge 4: 4

The colouring possibilities are:
V1: 1   V2: 2   V3: 1   V4: 2
V1: 1   V2: 2   V3: 1   V4: 3
V1: 1   V2: 2   V3: 3   V4: 2
V1: 1   V2: 3   V3: 1   V4: 2
V1: 1   V2: 3   V3: 1   V4: 3
V1: 1   V2: 3   V3: 2   V4: 3
V1: 2   V2: 1   V3: 2   V4: 1
V1: 2   V2: 1   V3: 2   V4: 3
V1: 2   V2: 1   V3: 3   V4: 1
V1: 2   V2: 3   V3: 1   V4: 3
V1: 2   V2: 3   V3: 2   V4: 1
V1: 2   V2: 3   V3: 2   V4: 3
V1: 3   V2: 1   V3: 2   V4: 1
V1: 3   V2: 1   V3: 3   V4: 1
V1: 3   V2: 1   V3: 3   V4: 2
V1: 3   V2: 2   V3: 1   V4: 2
V1: 3   V2: 2   V3: 3   V4: 1
V1: 3   V2: 2   V3: 3   V4: 2