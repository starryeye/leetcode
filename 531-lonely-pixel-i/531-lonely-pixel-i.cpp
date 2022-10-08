class Solution {
public:
    
    bool isValid(int i, int j, vector<vector<char>>& picture) {
        
        int ny = 0;
        int nx = 0;
        
        bool ret = true;
        
        picture[i][j] = 'W';
        
        
        ny = i + 1;
        nx = j;
        
        while(1) {
            if(ny < 0 || nx < 0 || ny >= picture.size() || nx >= picture[0].size())
                break;
            
            if(picture[ny][nx] == 'B') {
                isValid(ny, nx, picture);
                ret = false;
            }
            
            ny = ny + 1;
        }
        
        ny = i - 1;
        nx = j;
        
        while(1) {
            if(ny < 0 || nx < 0 || ny >= picture.size() || nx >= picture[0].size())
                break;
            
            if(picture[ny][nx] == 'B') {
                isValid(ny, nx, picture);
                ret = false;
            }
            
            ny = ny - 1;
        }
        
        ny = i;
        nx = j + 1;
        
        while(1) {
            if(ny < 0 || nx < 0 || ny >= picture.size() || nx >= picture[0].size())
                break;
            
            if(picture[ny][nx] == 'B') {
                isValid(ny, nx, picture);
                ret = false;
            }
            
            nx = nx + 1;
        }
        
        ny = i;
        nx = j - 1;
        
        while(1) {
            if(ny < 0 || nx < 0 || ny >= picture.size() || nx >= picture[0].size())
                break;
            
            if(picture[ny][nx] == 'B') {
                isValid(ny, nx, picture);
                ret = false;
            }
            
            nx = nx - 1;
        }
        

        
        return ret;
        
    }
    
    int findLonelyPixel(vector<vector<char>>& picture) {
        
        int answer = 0;
        
        for(int i = 0; i < picture.size(); i++) {
            for(int j = 0; j < picture[0].size(); j++) {
                
                if(picture[i][j] == 'B') {
                    if(isValid(i, j, picture))
                        answer++;
                }
            }
        }
        
        return answer;
    }
};