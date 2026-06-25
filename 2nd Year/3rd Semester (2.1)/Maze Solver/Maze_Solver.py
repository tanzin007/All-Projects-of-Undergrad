from collections import deque
import os
import time

# Maze Grid Layout
# '#' = Wall, 'S' = Start, 'E' = End/Goal, ' ' = Walkable Open Path
maze = [
    ["#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"],
    ["#", "S", " ", " ", "#", " ", " ", " ", " ", " ", " ", "#"],
    ["#", "#", "#", " ", "#", " ", "#", "#", "#", "#", " ", "#"],
    ["#", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", "#"],
    ["#", " ", "#", "#", "#", "#", "#", "#", " ", "#", " ", "#"],
    ["#", " ", "#", " ", " ", " ", " ", "#", " ", " ", " ", "#"],
    ["#", " ", "#", " ", "#", "#", " ", "#", "#", "#", " ", "#"],
    ["#", " ", " ", " ", "#", "E", " ", " ", " ", " ", " ", "#"],
    ["#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"]
]

def print_maze(current_maze):
    """Clears the terminal and prints the maze to create a live animation effect."""
    os.system('cls' if os.name == 'nt' else 'clear')
    for row in current_maze:
        print(" ".join(row))
    print("\n")
    time.sleep(0.15) # Small delay to make the animation visible

def solve_maze_bfs(start_pos):
    """Finds the shortest path using the Breadth-First Search (BFS) algorithm."""
    # Queue stores tuples of: (current_coordinates, path_taken_so_far)
    queue = deque([(start_pos, [start_pos])])
    
    # Set to keep track of visited cells to prevent infinite loops
    visited = set([start_pos])
    
    # 4 Possible movement directions: Up, Down, Left, Right
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    while queue:
        (r, c), path = queue.popleft()
        
        # Check if the destination is reached
        if maze[r][c] == 'E':
            return path
            
        # Visualize the exploration process (skip marking Start and End)
        if maze[r][c] != 'S' and maze[r][c] != 'E':
            maze[r][c] = '•' # '•' represents visited/explored nodes
            print_maze(maze)
            
        # Explore all 4 neighboring directions
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            
            # Boundary validation and checking for walls or already visited cells
            if 0 <= nr < len(maze) and 0 <= nc < len(maze[0]):
                if maze[nr][nc] != '#' and (nr, nc) not in visited:
                    visited.add((nr, nc))
                    queue.append(((nr, nc), path + [(nr, nc)]))
                    
    return None # Return None if no valid path exists

# Find the coordinates of the Start ('S') position dynamically
start = None
for r in range(len(maze)):
    for c in range(len(maze[0])):
        if maze[r][c] == 'S':
            start = (r, c)
            break

print("--- Starting BFS Maze Solver ---")
print_maze(maze)

# Run the BFS algorithm
shortest_path = solve_maze_bfs(start)

if shortest_path:
    # Reset the explored dots back to empty spaces for clean final rendering
    for r in range(len(maze)):
        for c in range(len(maze[0])):
            if maze[r][c] == '•':
                maze[r][c] = ' '

    # Mark the final correct shortest path with '*'
    for r, c in shortest_path:
        if maze[r][c] != 'S' and maze[r][c] != 'E':
            maze[r][c] = '*' 
            
    print("=======================================")
    print("🎉 SUCCESS! Shortest Path Found Using BFS:")
    print("=======================================")
    print_maze(maze)
else:
    print("❌ No path found to the exit!")
