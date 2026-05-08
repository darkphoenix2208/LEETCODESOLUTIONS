// Problem  : Valid Sudoku
// Difficulty: Medium
// Tags     : Array, Hash Table, Matrix
// URL      : https://leetcode.com/problems/valid-sudoku/
// Solved on: 2026-04-09 00:14
// ──────────────────────────────────────────────────

class Solution {
public:
    bool checkrow(vector<vector<char>>& board,int a,int b){
        for(int i=0;i<9;i++){
            if(b==i) continue;
            if(board[a][i] == board[a][b]) return false;
        }
        return true;
    }

    bool checkcol(vector<vector<char>>& board,int a,int b){
        for(int i=0;i<9;i++){
            if(a==i) continue;
            if(board[i][b] == board[a][b]) return false;
        }
        return true;
    }

    bool checkgrid(vector<vector<char>>& board,int a,int b){
        int start = a - a % 3;
        int end = b - b % 3;
        for(int i=start;i<start+3;i++){
            for(int j=end;j<end+3;j++){
                if(i==a && j==b) continue;
                if(board[i][j] == board[a][b]) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue; 
                if(!checkrow(board,i,j) || !checkcol(board,i,j) || !checkgrid(board,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
};


// Auto-commit update
