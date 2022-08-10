class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        
        dp[0][0] = grid[0][0];
        
        //첫번째 열은 비교 없이 누적
        for(int i = 1; i < grid.size(); i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        //첫번째 행은 비교 없이 누적
        for(int i = 1; i < grid[0].size(); i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i = 1; i < grid.size(); i++) {
            for(int j = 1; j < grid[0].size(); j++) {
                
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[grid.size()-1][grid[0].size()-1];
    }
    
    
    /*
    //DFS Time Limit
    
    int dy[4] = {1,0};
    int dx[4] = {0,1};
    
    void dfs(int y, int x, vector<vector<int>> grid, vector<vector<bool>>& check, int sum, int& total) {
        
        check[y][x] = true;
        
        if((y == grid.size() - 1) && (x == grid[0].size() - 1)) {
            if(total == -1)
                total = sum;
            else
                total = min(total, sum);
        }
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size())
                continue;
            
            if(check[ny][nx] == true)
                continue;
            
            dfs(ny, nx, grid, check, sum + grid[ny][nx], total);
            
            check[ny][nx] = false;
            
        }
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
        
        
        int total = -1;
        
        dfs(0, 0, grid, check, grid[0][0], total);
        
        return total;
    }
    */
};