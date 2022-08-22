class Solution {
public:
    
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    
    int bfs(vector<vector<int>>& grid) {
        
        
        queue<pair<int, int>> que;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) { //rotten이면
                    que.push({i, j}); //bfs 시작점이다.
                }
            }
        }
        
        int elapse = 0;
        while(!que.empty()) {
            
            int qsize = que.size();
            
            for(int a = 0; a < qsize; a++) {
                pair<int, int> cur = que.front();
                que.pop();
                
                for(int i = 0; i < 4; i++) {
                    pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
                    
                    if(next.first < 0 || next.second < 0 || next.first >= grid.size() || next.second >= grid[0].size())
                        continue;
                    
                    if(grid[next.first][next.second] == 1) { //fresh이면..
                        
                        grid[next.first][next.second] = 2; //rotten으로 바꾸고..
                        que.push(next); //이동..
                    }
                }
            }
            
            elapse++; //시간 tick 증가
        }
        
        //example 1에서 (2,2)가 rotten이고.. que로 들어가면.. quesize가 1로 잡혀서 실제로 fresh 바꿀게 없지만
        //시간은 1 증가된다.
        //마지막에 무조건 1이 증가되는 상황이 벌어진다. 따라서 0이 아니면 -1 해줌
        return elapse == 0 ? 0 : elapse - 1; 
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int ret = bfs(grid);
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ret;
    }
};