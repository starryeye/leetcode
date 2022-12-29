class Solution {
public:
    
    int dy[4] = {0,1,0,-1};
    int dx[4] = {1,0,-1,0};
    
    //discuss 리뷰 해보면 좋을듯..
    void dfs(int y, int x, int dir, vector<vector<int>>& matrix, vector<vector<bool>>& check, vector<int>& answer) {
        
        check[y][x] = true;
        
        answer.push_back(matrix[y][x]);
        
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        //next position이 matrix를 넘어가거나 이미 방문한 position 이면, 방향을 바꿔주고 next position을 정해준다.
        if(ny < 0 || nx < 0 || ny >= matrix.size() || nx >= matrix[0].size() || check[ny][nx] == true) {
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        
        //방향을 바꿨는데도 방문했거나 matrix를 넘어가면 끝이다.
        if(ny < 0 || nx < 0 || ny >= matrix.size() || nx >= matrix[0].size() || check[ny][nx] == true)
            return;
        
        dfs(ny, nx, dir, matrix, check, answer);
        
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<vector<bool>> check(matrix.size(), vector<bool>(matrix[0].size(), false));
        
        vector<int> answer;
        
        dfs(0, 0, 0, matrix, check, answer);
        
        return answer;
    }
};