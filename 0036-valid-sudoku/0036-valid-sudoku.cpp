class Solution {
    //discuss 방법이 좀 더 좋은듯..
    //https://leetcode.com/problems/valid-sudoku/discuss/15464/My-short-solution-by-C%2B%2B.-O(n2)
    
private:
    bool isValidRow(int row, vector<vector<char>>& board, vector<bool>& checkRow) {
        
        if(checkRow[row] == true)
            return true;
        
        vector<int> check(9, 0);
        
        for(int i = 0; i < 9; i++) {
            
            if(board[row][i] == '.')
                continue;
            
            check[board[row][i] - '1']++;
            
            if(check[board[row][i] - '1'] > 1)
                return false;
        }
        
        checkRow[row] = true;
        
        return true;
    }
    
    bool isValidColumn(int column, vector<vector<char>>& board, vector<bool>& checkColumn) {
        
        if(checkColumn[column] == true)
            return true;
        
        vector<int> check(9, 0);
        
        for(int i = 0; i < 9; i++) {
            
            if(board[i][column] == '.')
                continue;
            
            check[board[i][column] - '1']++;
            
            if(check[board[i][column] - '1'] > 1)
                return false;
        }
        
        checkColumn[column] = true;
        
        return true;
    }
    
    bool isValidSubBox(int row, int column, vector<vector<char>>& board, vector<vector<bool>>& checkSubBox) {
        
        int subRow = row / 3;
        int subColumn = column / 3;
        
        if(checkSubBox[subRow][subColumn] == true)
            return true;
        
        vector<int> check(9, 0);
        
        for(int i = subRow * 3; i < subRow * 3 + 3; i++) {
            for(int j = subColumn * 3; j < subColumn * 3 + 3; j++) {
                
                if(board[i][j] == '.')
                    continue;
                
                check[board[i][j] - '1']++;
                
                if(check[board[i][j] - '1'] > 1)
                    return false;
            }
        }
        
        checkSubBox[subRow][subColumn] = true;
        
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<bool> checkRow(9, false);
        vector<bool> checkColumn(9, false);
        vector<vector<bool>> checkSubBox(3, vector<bool>(3, false));
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                
                if(isValidRow(i, board, checkRow) == false)
                    return false;
                if(isValidColumn(j, board, checkColumn) == false)
                    return false;
                
                if(isValidSubBox(i, j, board, checkSubBox) == false)
                    return false;
            }
        }
        
        return true;
    }
};