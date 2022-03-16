class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> r;
        
        int m = matrix.size();
        if (m == 0)
            return r;
        
        int n = matrix[0].size();
        if (n == 0)
            return r;
        
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) 
        {
            dfs(matrix, pacific, i, 0); //걸리는 놈은 전부 pacific 바다임 -> pacific에 저장
            dfs(matrix, atlantic, i, n-1); //걸리는 놈은 전부 atlantic 바다임 -> atlantic에 저장

        }
        
        for (int j = 0; j < n; j++) 
        {
            dfs(matrix, pacific, 0, j); //걸리는 놈은 전부 pacific 바다임 -> pacific에 저장
            dfs(matrix, atlantic, m-1, j); //걸리는 놈은 전부 atlantic 바다임 -> atlantic에 저장
        }

        
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (pacific[i][j] && atlantic[i][j]) //중복인놈 정답
                {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    
                    r.push_back(tmp);
                }
            }
        }
        return r;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true; //각 바다를 뜻하는 visit
        
        
        
        //dfs 할 조건 = 방문 하지 않았으며.. 경계선을 넘지 않고, 현재보다 높아야함
        //up
        if (i-1 >= 0 && visited[i-1][j] != true && matrix[i-1][j]>=matrix[i][j])
            dfs(matrix, visited, i-1, j);
        //down
        if (i+1 < m && visited[i+1][j] != true && matrix[i+1][j]>=matrix[i][j])
            dfs(matrix, visited, i+1, j);
        //left
        if (j-1 >= 0 && visited[i][j-1] != true && matrix[i][j-1]>=matrix[i][j])
            dfs(matrix, visited, i, j-1);
        //right
        if (j+1 <n && visited[i][j+1] != true && matrix[i][j+1]>=matrix[i][j])
            dfs(matrix, visited, i, j+1);

    }
};

//dfs 두 바다를 한꺼번에 고려하며 ... 해결할 생각하면 너무 복잡하다...
/*class Solution {
public:
    // 0 : 방문 x
    // 1 : 방문중 
    // 2 : Pacific Ocean
    // 3 : Atlantic Ocean
    // 4 : both
    
    int ret(int y, int x, int ny, int nx, vector<vector<int>>& map)
    {
        if(m[y][x] == 1)
        {
            if(ny < 0 || nx < 0 || map[ny][nx] == 2)
            {
                return 2;
            }
            else if(ny >= m || nx >= n || map[ny][nx] == 3)
            {
                return 3;
            }
            else
            {
                return 1;
            }
        }
        else if(m[y][x] == 2)
        {
            if(ny >= m || nx >= n)
            {
                return 4;
            }
            else
            {
                return 1;
            }
        }
        else if(m[y][x] == 3)
        {
            if(ny < 0 || nx < 0)
            {
                return 4;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 4;
        }
        
    }
    
    
    void dfs(vector<vector<int>& h, vector<vector<int>& map, int y, int x)
    {
        if(map[y][x] == 0)
        {
            map[y][x] = 1;
            
            for(int i =0; i<4; i++)
            {
                ny += dy[i];
                nx += dx[i];
                
                if(h[y][x] >= h[ny][nx])
                {
                    
                    map[y][x] = ret(y, x, ny, nx);
                    
                    
                    if(map[ny][nx] == 0)
                    {
                        dfs();
                    }
                    else
                    {
                        return;
                    }
                }
                
                    
            }
        }
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights.size();
        
        vector<vector<int>> map(m, vector<int>(n,0));
        
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                dfs;
            }
        }
    }
    
private:
    dy[4] = {0,0,-1,1};
    dx[4] = {-1,1,0,0};

    int m = 0;
    int n = 0;
    
};*/