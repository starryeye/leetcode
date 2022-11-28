class Solution {
public:
    
    int dy[8] = {2, 1,-1,-2,-2,-1, 1, 2};
    int dx[8] = {1, 2, 2, 1,-1,-2,-2,-1};
    
    //아래 Time Limit을 뚫기 위한 로직은 수학적으로 그러한지 분석 필요..
    int minKnightMoves(int x, int y) {
        
        int answer = 0;
        
        //예외처리
        if(y == 0 && x == 0)
            return answer;
        
        
        //unordered_set, unordered_map은 key로 pair를 쓰지 못하지만..
        //set, map은 사용가능한듯..
        set<pair<int, int>> check;
        
        queue<pair<int, int>> que;
        
        que.push({0, 0});
        check.insert({0, 0});
        
        //Time Limit을 뚫기 위함..
        x = abs(x);
        y = abs(y);
        
        
        while(!que.empty()) {
            
            int queSize = que.size();
            
            for(int a = 0; a < queSize; a++) {
                
                int cy = que.front().first;
                int cx = que.front().second;
                que.pop();
                
                //Time Limit을 뚫기 위함..
                if (cy < -2 || cx < -2) continue;
		        if (cy > y+2 || cx > x+2) continue;
                
                for(int i = 0; i < 8; i++) {
                    
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];
                    
                    if(ny == y && nx == x)
                        return answer + 1;
                
                    if(check.find({ny, nx}) != check.end())
                        continue;
                
                    que.push({ny, nx});
                    check.insert({ny, nx});
                }
                
            }
            
            answer++;
            
        }
        
        return -1; //구색 맞추기 용
        
    }
};