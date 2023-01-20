class Solution {
public:
    
    int racecar(int target) {
        
        // 1. Initialize double ended queue as 0 moves, 0 position, +1 velocity
        queue<vector<int>> q;
        
        q.push({0, 0, 1});
        
        while (!q.empty()) {
            
            vector<int> item = q.front();
            q.pop();
            
            // (moves) moves, (pos) position, (vel) velocity)
            int moves = item[0];
            int pos = item[1];
            int vel = item[2];
            
            if (pos == target) 
                return moves;
            
            // Avoid integer overflow - stop whenever we've passed twice the magnitude of target.
            if (abs(pos) > 2 * target) 
                continue;
            
            // 2. Always consider moving the car in the direction it is already going
            q.push({moves + 1, pos + vel, 2 * vel});
            
            // 3. Only consider changing the direction of the car if one of the following conditions is true
            //    i.  The car is driving away from the target.
            //    ii. The car will pass the target in the next move.  
            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
            }
        }
        
        return 0;
    }
    
    /*
    //time limit
    char dx[2] = {'A', 'B'};
    
    void next(char instruction, int& position, int& speed) {
        
        if(instruction == 'A') {
            
            position += speed;
            speed *= 2;
        }else if(instruction == 'R') {
            
            if(speed > 0)
                speed = -1;
            else
                speed = 1;
        }
    }
    
    int bfs(int start, int target) {
        queue<pair<int, int>> que;
        
        que.push({0, 1});
        
        int tick = 0;
        
        while(!que.empty()) {
            
            int queSize = que.size();
            
            for(int a = 0; a < queSize; a++) {
                
                int cp = que.front().first;
                int cs = que.front().second;
                que.pop();
                
                if(cp == target) 
                    return tick;
                
                for(int i = 0; i < 2; i++) {
                    int np = cp;
                    int ns = cs;
                    
                    next(dx[i], np, ns);
                    
                    que.push({np, ns});
                }
            }
            
            tick++;
        }
        
        return -1; // 구색 맞추기용
    }
    
    int racecar(int target) {
        return bfs(0, target);
    }
    */
};