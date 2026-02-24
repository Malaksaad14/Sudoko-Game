#pragma once
#include <vector>
#include <string>
#include <iosfwd>

class SudokuBoard {
public:
    SudokuBoard();

    // Access
    int  get(int r, int c) const;
    bool set(int r, int c, int val);   // val in [0..9], 0 clears the cell
    bool isEmpty(int r, int c) const;
    bool isValid(int r, int c, int val) const; // check if placing 'val' here is valid
    bool isSolved() const;

    // I/O
    void print(std::ostream& os) const;
    bool loadFromFile(const std::string& path);
    bool saveToFile(const std::string& path) const;

    // Utilities
    void clearCell(int r, int c);
    void setBoard(const std::vector<std::vector<int>>& b);

private:
    std::vector<std::vector<int>> board; // 9x9; 0 means empty
    bool inRange(int r, int c) const;
};
