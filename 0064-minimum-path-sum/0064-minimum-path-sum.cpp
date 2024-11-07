class Solution {
public:
    // 오른쪽 or 아래로만 이동 가능

    // dp[i][j]
    //      상태 : (i, j) 좌표에 존재
    //      값 : 최소 합
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // DP 배열 생성 및 첫 번째 셀 초기화
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        
        // 첫 번째 행 초기화
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        
        // 첫 번째 열 초기화
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        // 나머지 DP 테이블 채우기
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        // 도착점까지의 최소 경로 합 반환
        return dp[m - 1][n - 1];
    }
};