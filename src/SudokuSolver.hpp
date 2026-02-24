#pragma once
class SudokuBoard;

class SudokuSolver {
public:
    // Returns true if solved; modifies the board in-place.
    bool solve(SudokuBoard& board);

private:
    bool findEmpty(const SudokuBoard& board, int& r, int& c);
};
