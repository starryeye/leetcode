class Solution {
public:
    
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    
    void dfs(int y, int x, queue<pair<int, int>>& que, vector<vector<bool>>& check, vector<vector<int>>& grid) {
        
        check[y][x] = true;
        que.push({y, x});
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size())
                continue;
            if(check[ny][nx] == true)
                continue;
            if(grid[ny][nx] == 0)
                continue;
            
            dfs(ny, nx, que, check, grid);
        }
    }
    
    int bfs(int y, int x, vector<vector<int>>& grid, vector<vector<bool>>& check) {
        
        queue<pair<int, int>> que;
        dfs(y, x, que, check, grid);
        
        int tick = 0;
        
        while(!que.empty()) {
            
            int queSize = que.size();
            for(int s = 0; s < queSize; s++) {
                
                int cy = que.front().first;
                int cx = que.front().second;
                que.pop();
                
                for(int i = 0; i < 4; i++) {
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];
                    
                    if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size())
                        continue;
                    if(check[ny][nx] == true)
                        continue;
                    
                    //신대륙 발견
                    if(grid[ny][nx] == 1) {
                        return tick;
                    }
                    
                    que.push({ny, nx});
                    check[ny][nx] = true;
                }
                
            }
            tick++;
            
        }
        
        return tick - 1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int answer = 0;
        
        vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                
                if(grid[i][j] == 1) {
                    answer = bfs(i, j, grid, check);
                    return answer;
                }
            }
        }
        
        return answer;
    }
};