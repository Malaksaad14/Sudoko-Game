#include "SudokuGame.hpp"
#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include <iostream>
#include <sstream>
#include <vector>

static const std::vector<std::vector<int>> kDefaultPuzzle = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},

    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9},
};

SudokuGame::SudokuGame() {
    board = new SudokuBoard();
    solver = new SudokuSolver();
    board->setBoard(kDefaultPuzzle);
}

void SudokuGame::showMenu() const {
    std::cout << "1) Enter a move\n"
                 "2) Solve automatically\n"
                 "3) Load puzzle from file\n"
                 "4) Save current puzzle to file\n"
                 "5) Exit\n";
    std::cout << "Choice: ";
}

bool SudokuGame::readTriple(int& r, int& c, int& v) const {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    if (!(iss >> r >> c >> v)) return false;
    if (r < 1 || r > 9) { std::cout << "Row must be between 1 and 9.\n"; return false; }
    if (c < 1 || c > 9) { std::cout << "Column must be between 1 and 9.\n"; return false; }
    if (v < 1 || v > 9) { std::cout << "Value must be between 1 and 9.\n"; return false; }
    return true;
}

void SudokuGame::handleEnterMove() {
    std::cout << "Enter row (1-9), column (1-9), and value (1-9): ";
    int r, c, v;
    if (!readTriple(r,c,v)) return;
    int rr = toIndex(r), cc = toIndex(c);
    if (!board->isValid(rr, cc, v)) {
        std::cout << "Invalid move (violates row/column/box constraints).\n";
        return;
    }
    board->set(rr, cc, v);
    std::cout << "Move accepted!\n";
}

void SudokuGame::handleSolve() {
    if (solver->solve(*board)) {
        std::cout << "Puzzle solved!\n";
    } else {
        std::cout << "Unsolvable puzzle.\n";
    }
}

void SudokuGame::handleLoad() {
    std::cout << "Enter file path to load: ";
    std::string path; std::getline(std::cin, path);
    if (board->loadFromFile(path)) {
        std::cout << "Loaded successfully.\n";
    } else {
        std::cout << "Failed to load puzzle. Make sure it's a 9x9 grid with digits or '.' for empty.\n";
    }
}

void SudokuGame::handleSave() {
    std::cout << "Enter file path to save: ";
    std::string path; std::getline(std::cin, path);
    if (board->saveToFile(path)) {
        std::cout << "Saved.\n";
    } else {
        std::cout << "Failed to save.\n";
    }
}

void SudokuGame::run() {
    bool running = true;
    while (running) {
        board->print(std::cout);
        showMenu();
        std::string line; std::getline(std::cin, line);
        int choice = 0;
        std::istringstream iss(line);
        if (!(iss >> choice)) {
            std::cout << "Please enter a number from 1 to 5.\n";
            continue;
        }
        switch (choice) {
            case 1: handleEnterMove(); break;
            case 2: handleSolve(); break;
            case 3: handleLoad(); break;
            case 4: handleSave(); break;
            case 5: running = false; break;
            default: std::cout << "Invalid choice.\n"; break;
        }
    }
    std::cout << "Goodbye!\n";
}
