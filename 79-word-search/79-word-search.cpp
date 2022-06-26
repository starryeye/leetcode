

class Solution {
public:
    
    struct pos{
        int y, x;
        pos(int _y, int _x) {y=_y; x=_x;}
    };
    
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& check, pos start, string word, int wordPos) {
        
        check[start.y][start.x] = true;
        
        if(word.size() == wordPos)
            return true; //찾았다!
        
        
        for(int i=0; i<4; i++) {
            pos next(start.y + dy[i], start.x + dx[i]);
            
            if(next.x < 0 || next.y < 0 || next.x >= board[0].size() || next.y >= board.size())
                continue;
            
            if(check[next.y][next.x] == true)
                continue;
            
            if(board[next.y][next.x] != word[wordPos])
                continue;
            
            if(dfs(board, check, next, word, wordPos + 1))
                return true; //찾았데!!
            
            //나중에 쓰일 수도 있는 경우가 있다.. false로 바꿔준다.
            check[next.y][next.x] = false;
        }
        
        return false;// 못찾음
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        
        
        for(int i=0; i < board.size(); i++) {
            for(int j=0; j < board[0].size(); j++) {
                
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> check(n, vector<bool>(m, false));
                    
                    if(dfs(board, check, pos(i, j), word, 1))
                        return true;
                }
            }
        }
        
        return false;       
        
        
    }
};