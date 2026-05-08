// Problem  : Design Spreadsheet
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Design, Matrix
// URL      : https://leetcode.com/problems/design-spreadsheet/
// Solved on: 2026-04-09 00:11
// ──────────────────────────────────────────────────

class Spreadsheet {
    vector<vector<int>> grid;

public:
    Spreadsheet(int rows) {
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        string x = "", y = "";
        int i = 1;
        while (formula[i] != '+') x += formula[i++];
        i++;
        while (i < formula.size()) y += formula[i++];
        return getOperandValue(x) + getOperandValue(y);
    }

private:
    int getOperandValue(string s) {
        if (isalpha(s[0])) {
            int col = s[0] - 'A';
            int row = stoi(s.substr(1)) - 1;
            return grid[row][col];
        } else {
            return stoi(s);
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

// Auto-commit update
