class Solution {
public:
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        while (sx < tx && sy < ty) {
            
            if (tx < ty) 
                ty %= tx;
            else 
                tx %= ty;
        }
            
        return sx == tx && sy <= ty && (ty - sy) % sx == 0 ||
               sy == ty && sx <= tx && (tx - sx) % sy == 0;
    }
    
    /*
    //time limit
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        // (1, 1) -> (1, 2)
        // (1, 2) -> (3, 2)
        // (3, 2) -> (3, 5)
        //(3, 5)의 전 단계는 무조건 (3, 2) 이다..
        
        while(1) {
            
            if(sx == tx && sy == ty)
                return true;
            
            if(sx > tx && sy > ty)
                return false;
            
            if(tx < 1 || ty < 1)
                return false;
            
            if(tx < ty)
                ty -= tx;
            else if(tx > ty)
                tx -= ty;
            else
                ty -= tx; // 아무거나 빼주기..?
        }
        
        return false; //구색 맞추기
    }
    */
    /*
    //time limit
    bool bfs(int sx, int sy, int tx, int ty) {
        
        queue<pair<int, int>> que;
        
        que.push({sx, sy});
        
        while(!que.empty()) {
            
            int cx = que.front().first;
            int cy = que.front().second;
            que.pop();
            
            
            if(cx > tx || cy > ty)
                continue;
            
            
            //(x, x + y)
            int nx = cx;
            int ny = cx + cy;
            
            if(tx == nx && ty == ny)
                return true;
            
            que.push({nx, ny});
            
            
            //(x + y, y)
            nx = cx + cy;
            ny = cy;
            
            if(tx == nx && ty == ny)
                return true;
            
            que.push({nx, ny});
        }
        
        return false;
    }
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        //처음 부터 같은 경우 처리
        if(sx == tx && sy == ty)
            return true;
        
        return bfs(sx, sy, tx, ty);
    }
    */
};