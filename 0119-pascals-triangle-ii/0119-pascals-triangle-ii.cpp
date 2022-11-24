class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> pascal;
        
        pascal.push_back({1});
        
        for(int i = 1; i <= rowIndex; i++) {
            
            vector<int> row;
            
            for(int j = 0; j < i + 1; j++) {
                
                if(j == 0 || j == i)
                    row.push_back(1);
                else {
                    row.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
                }
            }
            
            pascal.push_back(row);
        }
        
        return pascal.back();
    }
};