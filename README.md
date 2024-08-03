# N-Queens Visualization Project

## About the Project

This repository contains an implementation of the N-Queens problem, a classic computer science challenge that involves placing N chess queens on an N×N chessboard such that no two queens threaten each other. This implementation includes a visual representation of the board state as the algorithm progresses and finds solutions.

### Features

- **N-Queens Solver:** Recursively places queens on the board and finds all possible solutions.
- **Visual Representation:** Displays the chessboard state at each step of the algorithm, highlighting the positions of the queens.
- **Solution Count:** Keeps track of the total number of solutions found for the given N.

### Implementation Details

The project is implemented in C++. The main components of the code include:

- **Board Printing Function:** Prints the current state of the chessboard with queens placed.
- **Safety Check Function:** Checks if placing a queen at a given position is safe.
- **N-Queens Solver Function:** Recursively places queens on the board and finds all solutions.

### Example Usage

1. **Input:**
    ```ruby
    Enter the number of queens (N): 4
    ```

2. **Output:**
    ```ruby
    [Solution found]
     Q  .  .  . 
     .  .  Q  . 
     .  .  .  Q 
     .  Q  .  . 
     
     [Solution found]
     Q  .  .  . 
     .  .  Q  . 
     .  .  .  Q 
     .  Q  .  . 
     
    Total solutions found: 2
    ```

### Code Overview

The project comprises several key functions:

- **printBoard:** Displays the chessboard state, marking the positions of the queens.
- **isSafe:** Determines if it's safe to place a queen at a particular position by checking the current board state.
- **solveNQueens:** Recursively attempts to place queens on the board, backtracking when necessary to find all solutions.

### Contributing

Contributions are welcome! If you have suggestions, improvements, or bug fixes, please fork the repository and submit a pull request.

### License

This project is licensed under the MIT License.
