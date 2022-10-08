class Solution {
public:
    //Hash table 로 푸는 방법은 discuss를 참고 해보자..
    
    //시작점 (i, j)좌표에서 4개의 방향으로 쭉 가면서 B가 있는지 탐색한다.
    //B가 있으면 그 B를 시작점으로 하여 동일한 작업을 해준다.
    //B는 W로 바꾸어준다.
    //시작점 제외하고 B가 탐색되면 return 값은 false이다.
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
                    if(isValid(i, j, picture)) //true이면 lonely pixel 이다.
                        answer++;
                }
            }
        }
        
        return answer;
    }
};