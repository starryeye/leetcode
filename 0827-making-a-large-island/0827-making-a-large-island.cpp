class Solution {
public:
    int k=2; // 섬을 구분하는 용도.. 0, 1은 이미 의미가 있으므로 2부터 시작한다.
    
    unordered_map<int,int> mp; //key: k(섬 구분용), value: 섬의 넓이
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        k=2;
        
        mp.clear();
        
        int area=0;  
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j]) { //섬이라면
                    
                    dfs(grid,i,j);
                    
					// We have to find the largest island in case there are no 0's in the grid
                    area = max(area, mp[k]); //섬의 넓이
                    
                    k++; //다음 섬은 +1 해줌
                }
            }
        }
        
        
        queue<pair<int,int>> q; //섬이 아닌 부분, 0을 1로 바꿀 단 하나의 좌표을 찾기 위함.
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == 0) //섬이 아니라면..
                    q.push({i,j});
            }
        }
        
        while(!q.empty()) {
            
            auto p = q.front();
            q.pop();
            
            int x = p.first;
            int y = p.second;
            
			// Unordered Set to make sure the islands are unique
            unordered_set<int> s; //key : k(섬 구분 용)
            int tmp = 0; // 현재 좌표에 인접한 섬의 넓이를 더해줄 변수
            
            for(int i = 0; i < 4; i++) {
                
                int xx = dx[i]+x;
                int yy = dy[i]+y;
                
                if(xx < 0 || yy < 0 || xx >= m || yy >= n)
                    continue;
                
                if(grid[xx][yy] == 0) // 0에서 1로 바꿀 단하나의 좌표이므로.. 다른 0으로 가면 안됨.
                    continue;
                
                int val = grid[xx][yy]; // 섬을 구분하는 숫자가 리턴됨.
                
                if(s.find(val) == s.end()) { //방문하지 않은 섬만 본다.
                    
                    s.insert(val); //방문했다고 남김.
                    tmp += mp[val]; //tmp에 해당 섬의 넓이를 더해준다.
                }
            }
            
            area = max(area, tmp+1); //현재 좌표에 인접한 모든 섬의 넓이와 현재 좌표 넓이(1)을 모두 더하여 최고값 비교
        }

        return area;
    }
    
    void dfs(vector<vector<int>> &grid, int i, int j){
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        
        if(grid[i][j] != 1) //지나왔던 좌표는 섬 구분 숫자로 되어 있으므로.. 자동으로 check가 된다.
            return;
        
        mp[k]++; //섬의 넓이를 업데이트 해줌
        grid[i][j] = k; //섬 구분 숫자로 업데이트
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
};