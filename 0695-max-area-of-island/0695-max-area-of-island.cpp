class Solution {
private:
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    
    
public:
    
    
    void dfs(int y, int x, vector<vector<bool>>& check, vector<vector<int>> grid, int& count) {
        
        check[y][x] = true;
        
        for(int i = 0; i < 4; i++) {
            
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size())
                continue;
            
            if(check[ny][nx] == true || grid[ny][nx] == 0)
                continue;
            
            count++;
            dfs(ny, nx, check, grid, count);
        }
    }    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int answer = 0;
        
        vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                
                if(check[i][j] == false && grid[i][j] == 1) {
                    
                    int count = 1;
                    dfs(i, j, check, grid, count);
                    
                    answer = max(answer, count);
                }
                   
            }
        }
        
        return answer;
    }
};