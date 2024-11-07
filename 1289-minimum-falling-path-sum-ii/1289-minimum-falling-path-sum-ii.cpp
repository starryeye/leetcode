class Solution {
public:

    // dp[i][j]
    //      상태 : i index 행까지 고려, 마지막에 j 열을 고름
    //      값 : 최소 값
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            dp[0][i] = grid[0][i]; // 첫 행은 그자체
        }

        for (int i = 1; i < n; i++) {

            int firstMin = INT_MAX;
            int firstMinColumnIndx = -1;
            int secondMin = INT_MAX;
            int secondMinColumnIndx = -1;

            // [i - 1] 에서 가장 작은값과 그 인덱스, 두번째로 작은값과 그 인덱스 찾기
            for (int j = 0; j < m; j++) {

                if (dp[i - 1][j] < firstMin) {
                    if (firstMin != -1) {
                        secondMin = firstMin;
                        secondMinColumnIndx = firstMinColumnIndx;
                    }
                    firstMin = dp[i - 1][j];
                    firstMinColumnIndx = j;
                } else if (dp[i - 1][j] < secondMin) {
                    secondMin = dp[i - 1][j];
                    secondMinColumnIndx = j;
                }
            }

            
            // dp 업데이트
            for (int j = 0; j < m; j++) {
                
                if (j == firstMinColumnIndx) {
                    dp[i][j] = dp[i - 1][secondMinColumnIndx] + grid[i][j];
                } else {
                    dp[i][j] = dp[i - 1][firstMinColumnIndx] + grid[i][j];
                }
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

    // 참고 i - 1 만 사용하기 때문에 dp 1차원으로 최적화 가능하다.
};