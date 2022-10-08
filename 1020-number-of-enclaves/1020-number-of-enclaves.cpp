class Solution {

private:
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
    
public:
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& check) {
        check[i][j] = true;
        grid[i][j] = 0; // 0으로 변경함
        
        for(int a = 0; a < 4; a++) {
            int ny = i + dy[a];
            int nx = j + dx[a];
            
            if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size())
                continue;
            
            if(grid[ny][nx] == 0)
                continue;
            
            if(grid[ny][nx] == 1)
                dfs(ny, nx, grid, check);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int answer = 0;
        
        //맨 윗줄, 맨 아랫줄 만 검사
        for(int i = 0; i < grid[0].size(); i++) {
            if(grid[0][i] == 1) {
                vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
                dfs(0, i, grid, check);
            }
            
            if(grid[grid.size()-1][i] == 1) {
                vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
                dfs(grid.size() - 1, i, grid, check);
            }
        }
        
        //맨 왼쪽 줄, 맨 오른쪽 줄 만 검사
        for(int i = 1; i < grid.size() - 1; i++) {
            if(grid[i][0] == 1) {
                vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
                dfs(i, 0, grid, check);
            }
            
            if(grid[i][grid[0].size() - 1] == 1) {
                vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
                dfs(i, grid[0].size() - 1, grid, check);
            }
        }
        
        //정답 확인
        for(int i = 1; i < grid.size() - 1; i++) {
            for(int j = 1; j < grid[0].size() - 1; j++) {
                if(grid[i][j] == 1)
                    answer++;
            }
        }
        
        return answer;
    }
};