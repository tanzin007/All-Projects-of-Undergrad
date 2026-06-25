# BFS Maze Solver with Live Animation (Python)

A Python-based visual simulation that solves a 2D grid maze using the Breadth-First Search (BFS) algorithm. The project beautifully demonstrates how a Queue (`collections.deque`) data structure is utilized to find the absolute shortest path in an unweighted graph/grid.

## 🚀 Data Structure & Algorithm breakdown

1. **Queue (FIFO)**: BFS explores the maze level by level. By using a First-In-First-Out queue, the program ensures that it evaluates closer paths before moving further away, mathematically guaranteeing the shortest path.
2. **Time Complexity**: $O(V + E)$ where $V$ is the number of open cells and $E$ is the possible movements (edges).
3. **Space Complexity**: $O(V)$ due to the storage requirement of the `visited` set and the queue state.

## 🎮 Features
* **Live Terminal Animation**: Uses runtime screen clearing to showcase how the algorithm branches out (`•`) across the grid in real-time.
* **Optimal Path Highlighting**: Wipes exploratory markers upon completion to strictly draw the solution path using (`*`).
* **Memory Efficient**: Leverages Python's optimal `deque` array wrapper for high-performance double-ended popping.
