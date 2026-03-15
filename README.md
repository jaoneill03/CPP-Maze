# C++ Maze Generator

A C++ program that procedurally generates a random maze of any size
and prints it in ASCII format to an output file.

## How to compile & run

**Compile:**
```bash
g++ Maze.cpp DisjointSet.cpp -o maze
```

**Run:**
```bash
./maze   
```

**Example:**
```bash
./maze 5 5 maze.txt
```

## Example output
```
 _ _ _ _ _
  _| |_ _  |
 |  _| | _||
 | |  _|_  |
 |_ _|   _ |
 |_ _ _|_ _|
```

## How it works

- Each cell in the maze tracks whether its **south** and **east** walls are standing
- A **disjoint set** (union-find) tracks which cells are connected
- The generator randomly picks a cell and a neighbor, and knocks down
  the wall between them if they aren't already connected
- This repeats until all cells belong to one connected set, guaranteeing
  a perfect maze with exactly one path between any two points
- The finished maze is printed in ASCII using `|` for vertical walls
  and `_` for horizontal walls

## Files

- `Maze.h` — Maze class definition and CellWalls struct
- `Maze.cpp` — Maze generation and ASCII printing implementation
- `DisjointSet.cpp` — Union-find with union by size and path compression

## Technologies
- C++
- Disjoint sets (union-find)
- Randomized wall removal
- File I/O (ofstream)
