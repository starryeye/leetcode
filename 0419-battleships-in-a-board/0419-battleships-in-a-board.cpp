class Solution {
public:
    //조건 : 전함은 서로 인접하지 않는다.
    //DFS로 전함이 몇개가 있는지 가능하지만..
    //memory space O(1)로 가능한 솔루션
    // - 전함의 뱃머리만 카운트 하는 방법이다.
    // - 전함의 뱃머리 : 왼쪽과 윗쪽에 빈칸이면 뱃머리임
    int countBattleships(vector<vector<char>>& board) {
        
        int answer = 0;
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                
                if(board[i][j] == '.')
                    continue;
                
                if(i > 0 && board[i-1][j] == 'X')
                    continue;
                
                if(j > 0 && board[i][j-1] == 'X')
                    continue;
                
                answer++;
            }
        }
        
        return answer;
    }
};