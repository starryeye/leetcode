class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int cy, int cx, int prev) {
        
        if(cy < 0 or cx < 0 or cy >= grid.size() or cx >= grid[0].size())
            return 0;
        
        int cur = grid[cy][cx];
        
        if(prev >= cur)
            return 0;
        
        grid[cy][cx] = 0; // 한번 지나온 길은 다시 계산해보지 않아도 된다.
        
        int ret = max({
            dfs(grid, cy - 1, cx + 1, cur), 
            dfs(grid, cy, cx + 1, cur), 
            dfs(grid, cy + 1, cx + 1, cur)
            }) + 1;
        
        return ret;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        
        int res = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            res = max(res, dfs(grid, i, 0, -1e6));
        }
        
        return res - 1;
    }
};