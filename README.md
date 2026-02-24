# Sudoku Game

A console-based Sudoku game and solver written in C++. This project allows users to play Sudoku manually, solve puzzles automatically using a backtracking algorithm, and load/save puzzles from/to files.

## Features

- **Play Sudoku**: Manually enter moves (row, column, value) to solve the puzzle.
- **Auto-Solver**: Solve any valid Sudoku puzzle instantly using a built-in solver.
- **Load/Save**: Import puzzles from text files or save your current progress.
- **Input Validation**: Automatically checks if a move violates Sudoku rules (row, column, or 3x3 box constraints).

## Project Structure

- `src/main.cpp`: Entry point of the application.
- `src/SudokuGame.cpp/hpp`: Main game logic and menu handling.
- `src/SudokuBoard.cpp/hpp`: Represents the 9x9 grid and handles validation and I/O.
- `src/SudokuSolver.cpp/hpp`: Backtracking algorithm used to solve the puzzle.
- `CMakeLists.txt`: Configuration for building the project with CMake.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., GCC, Clang, or MSVC).
- [CMake](https://cmake.org/download/) installed on your system.

### Build Instructions

1.  Open a terminal in the project root directory.
2.  Create a build directory and navigate into it:
    ```bash
    mkdir build
    cd build
    ```
3.  Generate the build files:
    ```bash
    cmake ..
    ```
4.  Compile the project:
    ```bash
    cmake --build .
    ```

### Running the Game

After building, you can run the executable:

- **Windows**:
  ```bash
  .\sudoku.exe
  ```
- **Linux/macOS**:
  ```bash
  ./sudoku
  ```

## How to Play

Upon running the game, you will see a menu:

1.  **Enter a move**: Input the row (1-9), column (1-9), and value (1-9) to place a number on the board.
2.  **Solve automatically**: The computer will attempt to solve the current puzzle for you.
3.  **Load puzzle from file**: Enter the path to a text file containing a Sudoku puzzle.
4.  **Save current puzzle to file**: Save your current board state to a text file.
5.  **Exit**: Close the game.

## File Format

Puzzle files should be 9x9 grids of numbers. Use `0` or `.` to represent empty cells. Spaces between numbers are allowed.

Example `puzzle.txt`:
```txt
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```
