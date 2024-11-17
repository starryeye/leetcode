class Solution {
public:
/*
    int maximalRectangle(vector<vector<char>>& matrix) {
	    
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> memo(n, vector<int>(m, 0));
        // (i, j) 좌표에서 위로 1 이 몇이나 연속 되는지.. (높이, 세로)
	    
        // 초기화
        for (int j = 0; j < m; j++) {
            if(matrix[0][j] == '1') {
                memo[0][j] = 1;
            }
        }
   	    for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(matrix[i][j] == '1') {
                    memo[i][j] = memo[i - 1][j] + 1;
                }
            }
        }

	    int ret = 0;
	    for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {

                int h = memo[i][j];
                for(int k = j; k < m; ++k){
				    h = min(h, memo[i][k]);
				    ret = max(ret, (k - j + 1) * h);
			    }
            }
        }
		    
	    return ret;
    }
*/
    // 위 코드 보단 시간 복잡도에서 더 나음..
    // 진정한 DP 를 이용한다. 위는 사실상 이용하는게 아니라고 함..
    // 위 코드는 이해 되었지만.. 아래 코드는 이해 못함..
    int maximalRectangle(vector<vector<char>>& matrix) {

        // 빈 행렬이라면 최대 면적은 0
        if (matrix.empty()) return 0;
        
        int m = matrix.size();    // 행의 개수
        int n = matrix[0].size(); // 열의 개수
        
        // DP 배열 초기화
        vector<int> left(n, 0);     // 각 열에서의 왼쪽 경계
        vector<int> right(n, n);    // 각 열에서의 오른쪽 경계 (초기화는 열의 개수로 설정)
        vector<int> height(n, 0);   // 각 열에서의 높이 (히스토그램처럼 사용)
        
        int maxarea = 0; // 최대 직사각형 면적을 저장하는 변수
        
        // 각 행을 순회
        for (int i = 0; i < m; i++) {
            int cur_left = 0;    // 현재 행에서의 왼쪽 경계
            int cur_right = n;   // 현재 행에서의 오른쪽 경계
            
            // 1. 각 행에서 각 열에 대해 높이 갱신
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;  // 연속된 '1'이면 높이를 증가
                else
                    height[j] = 0; // '0'을 만나면 해당 열의 높이를 0으로 초기화
            }
            
            // 2. 각 행에서 각 열에 대해 왼쪽 경계 갱신
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    // 이전 행의 경계와 현재 행에서 확장 가능한 경계 중 큰 값 선택
                    left[j] = max(left[j], cur_left);
                } else {
                    // '0'을 만나면 현재 열의 왼쪽 경계 초기화
                    left[j] = 0;
                    cur_left = j + 1; // 다음 열부터 새로운 왼쪽 경계를 시작
                }
            }

            // 3. 각 행에서 각 열에 대해 오른쪽 경계 갱신 (오른쪽에서 왼쪽으로 탐색)
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    // 이전 행의 경계와 현재 행에서 확장 가능한 경계 중 작은 값 선택
                    right[j] = min(right[j], cur_right);
                } else {
                    // '0'을 만나면 현재 열의 오른쪽 경계 초기화
                    right[j] = n;
                    cur_right = j; // 이전 열부터 새로운 오른쪽 경계를 시작
                }
            }
            
            // 4. 각 행에서 각 열에 대해 최대 면적 계산
            for (int j = 0; j < n; j++) {
                // 각 열에서 가능한 직사각형 면적: 가로 길이 * 높이
                maxarea = max(maxarea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxarea; // 최대 면적 반환
    }
};