#include "SudokuSolver.hpp"
#include "SudokuBoard.hpp"

static int getCell(const SudokuBoard& b, int r, int c) { return b.get(r,c); }

bool SudokuSolver::findEmpty(const SudokuBoard& board, int& r, int& c) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (getCell(board,i,j) == 0) { r = i; c = j; return true; }
        }
    }
    return false;
}

bool SudokuSolver::solve(SudokuBoard& board) {
    int r, c;
    if (!findEmpty(board, r, c)) return true; // no empty cells -> solved
    for (int val = 1; val <= 9; ++val) {
        if (board.isValid(r, c, val)) {
            board.set(r, c, val);
            if (solve(board)) return true;
            board.set(r, c, 0); // backtrack
        }
    }
    return false; // trigger backtracking
}
