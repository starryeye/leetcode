class Solution {
public:
    struct point {
        int y;
        int x;
        
        point(int _y, int _x) {
            y = _y;
            x = _x;
        }
    };
    
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    
    //color로 채우기 
    void dfs(int color, point start, vector<vector<int>>& image, vector<vector<bool>>& check) {
        
        check[start.y][start.x] = true;
        
        int backupStartColor = image[start.y][start.x];
        image[start.y][start.x] = color;
        
        
        for(int i=0; i<4; i++) {
            point next(start.y + dy[i], start.x + dx[i]);
            
            if(next.y < 0 || next.y >= image.size() || next.x < 0 || next.x >= image[0].size())
                continue;
            
            if(check[next.y][next.x] == true)
                continue;
            
            if(image[next.y][next.x] != backupStartColor)
                continue;
            
            dfs(color, next, image, check);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int ny = image.size();
        int nx = image[0].size();
        
        vector<vector<bool>> check(ny, vector<bool>(nx, false));
        
        point start(sr, sc);
        
        dfs(color, start, image, check);
        
        return image;
    }
    
};