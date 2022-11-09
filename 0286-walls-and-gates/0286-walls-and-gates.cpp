class Solution {
public:
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    
    void bfs(int y, int x, vector<vector<int>>& rooms) {
        queue<pair<int, int>> que;
        que.push({y, x});
        int count = 0;
        
        while(!que.empty()) {
            
            count++;
            
            int queSize = que.size();
            
            for(int i = 0; i < queSize; i++) {
                
                pair<int, int> cur = que.front();
                que.pop();
                
                for(int ii = 0; ii < 4; ii++) {
                    
                    int ny = cur.first + dy[ii];
                    int nx = cur.second + dx[ii];
                    
                    if(ny < 0 || nx < 0 || ny >= rooms.size() || nx >= rooms[0].size())
                        continue;
                    
                    if(rooms[ny][nx] > count) {
                        rooms[ny][nx] = count;
                        que.push({ny, nx});
                    }
                }
            }
            
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        for(int i = 0; i < rooms.size(); i++) {
            for(int j = 0; j < rooms[0].size(); j++) {
                
                if(rooms[i][j] == 0) {
                    bfs(i, j, rooms);
                }
            }
        }
    }
};