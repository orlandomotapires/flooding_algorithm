# Flooding Algorithm

The flooding algorithm is a traversal technique used to explore all the vertices of a graph or a network. It is commonly used in network routing protocols, such as OSPF and IS-IS.

## Utility
Flooding is used in various domains:
- In computer networks, it helps in sending packets to every part of the network.
- In image processing, it helps in determining connected regions.
- In maze-solving algorithms, it helps in finding the shortest path.

## Complexity
The time complexity of the flooding algorithm is O(V+E) where V is the number of vertices and E is the number of edges.

## Files Description

- **Queue.h**: Contains the implementation of a queue data structure.
- **Graph.h**: Contains the implementation of a graph data structure.
- **Stack.h**: Contains the implementation of a stack data structure.
- **Flooding.h**: Contains the main logic for the flooding algorithm.
- **flooding_algorithm.c**: The main file that uses the flooding algorithm to solve a problem.

## Graph Construction
The graph is constructed using an adjacency matrix read from a file named `adj_a.txt`. This file contains the representation of the graph in matrix form.

## Contributing
Feel free to fork the repository and make changes. If you have any questions or feedback, please raise an issue.

