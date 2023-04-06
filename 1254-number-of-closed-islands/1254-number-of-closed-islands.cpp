class Solution {
    
private:
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    
    struct Area {
        int y, x, type;
    };
    
    void bfs(int y, int x, vector<vector<bool>>& check, vector<vector<int>>& grid) {
        
        Area start{y, x, grid[y][x]};
        check[y][x] = true;
        
        queue<Area> que;
        que.push(start);
        
        while(!que.empty()) {
            Area cur = que.front();
            que.pop();
            
            for(int i = 0; i < 4; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                
                if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size())
                    continue;
                
                if(cur.type != grid[ny][nx])
                    continue;
                
                if(check[ny][nx] == true)
                    continue;
                
                Area nArea{ny, nx, cur.type};
                que.push(nArea);
                check[ny][nx] = true;
            }
        }
    }
    
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int answer = 0;
        
        vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i = 0; i < grid[0].size(); i++) {
            
            if(check[0][i] == false)
                bfs(0, i, check, grid);
            
            if(check[grid.size() - 1][i] == false)
                bfs(grid.size() - 1, i, check, grid);
        }
        
        for(int i = 0; i < grid.size(); i++) {
                        
            if(check[i][0] == false)
                bfs(i, 0, check, grid);
            
            if(check[i][grid[0].size() - 1] == false)
                bfs(i, grid[0].size() - 1, check, grid);
        }
        
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                
                if(check[i][j] == false) {
                    bfs(i, j, check, grid);
                    
                    if(grid[i][j] == 0)
                        answer++;
                }
            }
        }
        
        return answer;
    }
};