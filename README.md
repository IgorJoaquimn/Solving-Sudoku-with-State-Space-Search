# Solving Sudoku with State Space Search
Igor Joaquim da Silva Costa

<hr>

### Introduction
This project implements a Sudoku solver using various state space search algorithms. The implemented algorithms include Breadth-First Search (BFS), Iterative Deepening Search (IDS), Uniform Cost Search (UCS), A* Search (A_STAR), and Greedy Best-First Search (GBFS).

### Usage

To run the program, use the following command-line format:
```
./solver <algorithm> <sudoku_config>
```

- `<algorithm>`: Choose one of the following algorithms to solve the Sudoku puzzle:
    - `B`: BFS
    - `I`: IDS
    - `U`: UCS
    - `A`: A_STAR
    - `G`: GBFS
- `<sudoku_config>`: Specify the Sudoku configuration as a string of 81 characters representing the puzzle, with '0' indicating empty cells.

### Compilation Instructions

Ensure that your system meets the following requirements for compiling the program:

- **Language**: C++
- **Compiler**: Gnu g++
- **Compilation Flags**: `-std=c++17 -g`
- **Language Version**: Standard C++17
- **Operating System (preferred)**: Linux kernel-based distributions, preferably Linux 5.15.

### Example

To solve a Sudoku puzzle using A* Search algorithm, the command would be:
```
`./solver A 107006450 025340008 060001070 053000029 610009800 000602007 001093200 008000000 040078591`
```

### Notes

- For Iterative Deepening Search (IDS), the program will display the value of the limit (`lim`) reached during the search process.
- Ensure that the Sudoku configuration is provided correctly, with '0' representing empty cells.

php
Copy code
./solver <algorithm> <sudoku_config>
<algorithm>: Choose one of the following algorithms to solve the Sudoku puzzle: B for BFS, I for IDS, U for UCS, A for A_STAR, or G for GBFS.
<sudoku_config>: Specify the Sudoku configuration as a string of 81 characters representing the puzzle, with '0' indicating empty cells.