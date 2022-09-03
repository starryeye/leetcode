class Solution {
public:
    
    int dy[8] = {-1,-1,-1,0,0,1,1,1};
    int dx[8] = {-1,1,0,-1,1,-1,0,1};
    
    int bfs(vector<vector<int>> grid, vector<vector<bool>>& check, int y, int x) {
        
        queue<pair<int, int>> que;
        
        check[y][x] = true;
        que.push({y, x});
        
        int tick = 0;
        
        while(!que.empty()) {
            
            int qsize = que.size();
            
            for(int a = 0; a < qsize; a++) {
                
                int cy = que.front().first;
                int cx = que.front().second;
                que.pop();
                
                if(cy == grid.size() -1 && cx == grid[0].size() -1)
                    return tick;
                
                for(int i = 0; i < 8; i++) {
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];
                    
                    if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size())
                        continue;
                    
                    if(grid[ny][nx] == 1 || check[ny][nx] == true)
                        continue;
                    
                    que.push({ny, nx});
                    check[ny][nx] = true;
                }
                
                
            }
            
            tick++;
        }
        
        return -1;
        
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1)
            return -1;
        
        
        vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
        
        int ret = bfs(grid, check, 0, 0);
        
        if(ret == -1)
            return ret;
        else
            return ret+1;
        //BFS내부에서 한칸 이동할때마다 +1이고.. 문제에선 몇칸이 걸리는지 이므로 최종적으로 +1 해준다.
    }
};