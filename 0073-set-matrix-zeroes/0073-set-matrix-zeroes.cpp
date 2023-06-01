class Solution {
public:
    void zeroUpdate(int y, int x, vector<vector<int>>& matrix) {
        
        for(int i = 0; i < matrix[0].size(); i++)
            matrix[y][i] = 0;
        
        for(int i = 0; i < matrix.size(); i++) {
            matrix[i][x] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<bool> row(matrix.size(), false);
        vector<bool> column(matrix[0].size(), false);
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                
                if(matrix[i][j] == 0) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                
                if(row[i] == true && column[j] == true) {
                    zeroUpdate(i, j, matrix);
                }
            }
        }
    }
};