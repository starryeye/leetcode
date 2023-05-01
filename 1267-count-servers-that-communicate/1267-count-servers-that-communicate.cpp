class Solution {
public:
    //curYX: 현재 index 재귀 1회당 +1, candi: 해당 줄에 server list
    
    int dfs_row(int curY, int curX, vector<int> candi, vector<vector<bool>>& check, vector<vector<int>>& grid) {
        
        if(curX == grid[0].size()) {
            
            if(candi.size() > 1) {
                
                int realCount = candi.size();
                
                for(auto c : candi) {
                    
                    if(check[curY][c] == false)
                        check[curY][c] = true;
                    else
                        realCount--;
                }
                return realCount;
            }else {
                return 0;
            }
        }
        
        if(grid[curY][curX] == 1) {
            candi.push_back(curX);
        }
        
        return dfs_row(curY, curX + 1, candi, check, grid);
    }
    
    int dfs_column(int curY, int curX, vector<int> candi, vector<vector<bool>>& check, vector<vector<int>>& grid) {
        
      if(curY == grid.size()) {
            
            if(candi.size() > 1) {
                
                int realCount = candi.size();
                
                for(auto c : candi) {
                    
                    if(check[c][curX] == false)
                        check[c][curX] = true;
                    else
                        realCount--;
                }
                return realCount;
            }else {
                return 0;
            }
        }
        
        if(grid[curY][curX] == 1) {
            candi.push_back(curY);
        }
        
        return dfs_column(curY + 1, curX, candi, check, grid);
    }
    
    int countServers(vector<vector<int>>& grid) {
        
        int answer = 0;
        
        //개수에 포함시켰는지 확인
        vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
        
        //첫번째 row 부터 마지막 row 까지 검사
        for(int i = 0; i < grid.size(); i++) {
            
            vector<int> candi;
            answer += dfs_row(i, 0, candi, check, grid);
        }
        
        //첫번째 column 부터 마지막 column 까지 검사
        for(int i = 0; i < grid[0].size(); i++) {
            
            vector<int> candi;
            answer += dfs_column(0, i, candi, check, grid);
        }
        
        return answer;
        
    }
};