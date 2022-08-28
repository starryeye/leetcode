class Solution {
public:
    
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    
    void findMe(vector<vector<char>> grid, int& y, int& x) {
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                
                if(grid[i][j] == '*') {
                    y = i;
                    x = j;
                    return;
                }
            }
        }
    }
    
    int bfs(int y, int x, vector<vector<char>> grid, vector<vector<bool>>& check) {
        
        queue<pair<int, int>> que;
        
        que.push({y, x});
        check[y][x] = true;
        
        int tick = 0;
        
        while(!que.empty()) {
            
            int qSize = que.size();
            
            for(int a = 0; a < qSize; a++) {
                
                pair<int, int> cur = que.front();
                que.pop();
                
                if(grid[cur.first][cur.second] == '#')
                    return tick;
                
                for(int i = 0; i < 4; i++) {
                    int ny = cur.first + dy[i];
                    int nx = cur.second + dx[i];
                    
                    if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size())
                        continue;
                    
                    if(grid[ny][nx] == 'X' || check[ny][nx] == true)
                        continue;
                    
                    que.push({ny, nx});
                    check[ny][nx] = true;
                }
                
            }
            
            tick++;
        }
        
        return -1;
    }
    
    int getFood(vector<vector<char>>& grid) {
        
        vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
        
        int y = 0;
        int x = 0;
        
        findMe(grid, y, x);
        
        return bfs(y, x, grid, check);
    }
};