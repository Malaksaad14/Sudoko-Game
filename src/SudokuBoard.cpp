#include "SudokuBoard.hpp"
#include <iostream>
#include <fstream>
#include <cctype>

SudokuBoard::SudokuBoard() : board(9, std::vector<int>(9, 0)) {}

bool SudokuBoard::inRange(int r, int c) const {
    return r >= 0 && r < 9 && c >= 0 && c < 9;
}

int SudokuBoard::get(int r, int c) const {
    return board[r][c];
}

bool SudokuBoard::isEmpty(int r, int c) const {
    return board[r][c] == 0;
}

void SudokuBoard::clearCell(int r, int c) {
    if (inRange(r,c)) board[r][c] = 0;
}

void SudokuBoard::setBoard(const std::vector<std::vector<int>>& b) {
    board = b;
}

bool SudokuBoard::isValid(int r, int c, int val) const {
    if (!inRange(r, c) || val < 1 || val > 9) return false;

    // Row check
    for (int j = 0; j < 9; ++j) {
        if (j != c && board[r][j] == val) return false;
    }
    // Column check
    for (int i = 0; i < 9; ++i) {
        if (i != r && board[i][c] == val) return false;
    }
    // 3x3 box check
    int br = (r / 3) * 3;
    int bc = (c / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int rr = br + i, cc = bc + j;
            if ((rr != r || cc != c) && board[rr][cc] == val) return false;
        }
    }
    return true;
}

bool SudokuBoard::set(int r, int c, int val) {
    if (!inRange(r, c)) return false;
    if (val == 0) { board[r][c] = 0; return true; }
    if (!isEmpty(r, c) && board[r][c] == val) return true; // already set
    if (!isValid(r, c, val)) return false;
    board[r][c] = val;
    return true;
}

bool SudokuBoard::isSolved() const {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == 0) return false;
        }
    }
    return true;
}

void SudokuBoard::print(std::ostream& os) const {
    auto printLine = [&]() {
        os << "-------------------------------------\n";
    };
    printLine();
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            int v = board[r][c];
            if (c == 0) os << " ";
            if (v == 0) os << ".";
            else os << v;
            if (c == 2 || c == 5) os << "  | ";
            else os << " ";
        }
        os << "\n";
        if (r == 2 || r == 5 || r == 8) printLine();
    }
}

bool SudokuBoard::loadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in) return false;
    std::vector<std::vector<int>> temp(9, std::vector<int>(9, 0));
    int r = 0, c = 0;
    std::string line;
    while (std::getline(in, line) && r < 9) {
        c = 0;
        for (char ch : line) {
            if (c >= 9) break;
            if (std::isdigit(static_cast<unsigned char>(ch))) {
                int v = ch - '0';
                temp[r][c++] = v;
            } else if (ch == '.' || ch == '0') {
                temp[r][c++] = 0;
            } else if (std::isspace(static_cast<unsigned char>(ch))) {
                continue;
            }
        }
        if (c == 9) ++r;
    }
    if (r != 9) return false;
    board = std::move(temp);
    return true;
}

bool SudokuBoard::saveToFile(const std::string& path) const {
    std::ofstream out(path);
    if (!out) return false;
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            int v = board[r][c];
            out << (v == 0 ? '.' : char('0' + v));
            if (c < 8) out << ' ';
        }
        out << '\n';
    }
    return true;
}
