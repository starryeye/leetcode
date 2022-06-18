class Solution {
public:
    //프로그래머스 정수 삼각형문제와 비슷
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> answer;
        
        answer.push_back({1});
        
        if(numRows == 1) {
            return answer;
        }
        
        //numRows -1 회 만큼 반복
        for(int i =1; i < numRows; i++) { // 행
            
            vector<int> row;
            for(int j=0; j < i+1; j++) { // 열, 열은 i+1 만큼의 요소를 가진다.
                
                if(j == 0 || j == i) { //양 끝일 경우
                    row.push_back(1);
                }else { // 끝 요소가 아닐 경우
                    row.push_back(answer[i-1][j-1] + answer[i-1][j]);
                }
            }
            answer.push_back(row);
        }
        
        return answer;
        
    }
};