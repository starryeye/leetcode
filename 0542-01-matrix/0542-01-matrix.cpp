class Solution {
public:
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    
    void bfs(vector<vector<int>>& mat) {  
        
        //방문 여부
        vector<vector<bool>> check(mat.size(), vector<bool>(mat[0].size(), false));
        
        queue<pair<int, int>> que;
        
        //0인 좌표를 한꺼번에 que에 다 넣어준다..
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                
                if(mat[i][j] == 1)
                    mat[i][j] = 10001;
                else {
                    que.push({i, j});
                    check[i][j];
                }
            }
        }
        
        int tick = 0;
        
        while(!que.empty()) {
            
            int queSize = que.size();
            
            for(int a = 0; a < queSize; a++) {
                int cy = que.front().first;
                int cx = que.front().second;
                que.pop();
                
                //최소 거리 갱신
                if(mat[cy][cx] != 0)
                    mat[cy][cx] = min(mat[cy][cx], tick);
                
                for(int i = 0; i < 4; i++) {
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];
                    
                    if(ny < 0 || nx < 0 || ny >= mat.size() || nx >= mat[0].size())
                        continue;
                    
                    if(check[ny][nx] == true || mat[ny][nx] == 0)
                        continue;
                    
                    que.push({ny, nx});
                    check[ny][nx] = true;
                }
            }
            
            tick++;
        }
        
    }
    

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        //0에서 출발하여 다음이 0이면 방문하지 않고 1이면 방문하여 최소 거리를 갱신해준다.
        bfs(mat);
        
        return mat;
    }
};



    //que에 한꺼번에 넣는 전략 말고.. 0이면 하나씩 해보는 전략을 선택하면..
    //10001로 초기화 하는 부분도 따로 빠져 나오기도 하고 시간이 오래 걸려서 time limit..
    //
/*
class Solution {
public:
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    
    void bfs(int y, int x, vector<vector<int>>& mat, vector<vector<bool>>& check) {            
        queue<pair<int, int>> que;
        check[y][x] = true;
        que.push({y, x});
        
        int tick = 0;
        
        while(!que.empty()) {
            
            int queSize = que.size();
            
            for(int a = 0; a < queSize; a++) {
                int cy = que.front().first;
                int cx = que.front().second;
                que.pop();
                
                //최소 거리 갱신
                if(mat[cy][cx] != 0)
                    mat[cy][cx] = min(mat[cy][cx], tick);
                
                for(int i = 0; i < 4; i++) {
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];
                    
                    if(ny < 0 || nx < 0 || ny >= mat.size() || nx >= mat[0].size())
                        continue;
                    
                    if(check[ny][nx] == true || mat[ny][nx] == 0)
                        continue;
                    
                    que.push({ny, nx});
                    check[ny][nx] = true;
                }
            }
            
            tick++;
        }
        
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        for(int i = 0; i < mat.size(); i++ ){
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 1)
                    mat[i][j] = 10001;
            }
        }
        
        
        //0에서 출발하여 다음이 0이면 방문하지 않고 1이면 방문하여 최소 거리를 갱신해준다.
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                
                //방문 여부
                vector<vector<bool>> check(mat.size(), vector<bool>(mat[0].size(), false));
        
                if(mat[i][j] == 0)
                    bfs(i, j, mat, check);
            }
        }
        
        return mat;
    }
};
*/