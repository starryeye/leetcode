class Solution {
public:
    struct point{
        int y, x;
        point(int _y, int _x) {y = _y; x = _x;}
    };
    
    int dy[4] = {0,0,-1,1};
    int dx[4] = {-1,1,0,0};
    
    int m = 0;
    int n = 0;
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& check, int i, int j)
    {
        queue<point> que;
        
        que.push(point(i, j));
        check[i][j] = true;
        
        while(!que.empty())
        {
            point pos = que.front();
            int cy = pos.y;
            int cx = pos.x;
            que.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                
                if(ny < 0 || nx < 0 || ny >= m || nx >= n)
                    continue;
                
                if(check[ny][nx] == false && grid[ny][nx] == '1')
                {
                    que.push(point(ny, nx));
                    check[ny][nx] = true;
                }
            }
            
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        int answer = 0;
        
        vector<vector<bool>> check(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(check[i][j] == false && grid[i][j] == '1')
                {
                    bfs(grid, check, i, j);
                    answer++;
                }
            }
        }
        
        return answer;
        
    }
};