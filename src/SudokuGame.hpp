#pragma once
#include <string>

class SudokuBoard;
class SudokuSolver;

class SudokuGame {
public:
    SudokuGame();
    void run();

private:
    SudokuBoard* board;
    SudokuSolver* solver;

    void showMenu() const;
    void handleEnterMove();
    void handleSolve();
    void handleLoad();
    void handleSave();

    // Helpers
    bool readTriple(int& r, int& c, int& v) const; // 1-based from user
    static int toIndex(int oneBased) { return oneBased - 1; }
};
