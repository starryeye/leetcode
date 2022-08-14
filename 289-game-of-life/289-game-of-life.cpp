class Solution {
public:
    int dy[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int dx[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
    
    int countLiveNeighborCell(vector<vector<int>>& board, int y, int x) {
        //주변에 살아있는 이웃 셀이 몇 개인지..
        
        int ret = 0;
        
        for(int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size())
                continue;
            
            if(board[ny][nx] == 1)
                ret++;
        }
        
        return ret;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> originBoard = board;
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                
                if(originBoard[i][j] == 0) {
                    
                    //죽어있는 세포
                    if(countLiveNeighborCell(originBoard, i, j) == 3)
                        board[i][j] = 1;  
                }else {
                    
                    //살아있는 세포
                    if(countLiveNeighborCell(originBoard, i, j) < 2)
                        board[i][j] = 0; //살아있는 셀은, 살아있는 이웃 셀이 2개 미만이면 죽는다.
                    else if(countLiveNeighborCell(originBoard, i, j) > 3)
                        board[i][j] = 0; //살아있는 셀은, 살아있는 이웃 셀이 3개 초과이면 죽는다.
                    else
                        board[i][j] = 1; //살아있는 셀은, 살아있는 이웃 셀이 2~3개 이면 산다.
                }
            }
        }
        
    }
};