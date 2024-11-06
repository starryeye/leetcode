class Solution {
public:

    // dp[k][i][j]
    //      상태 : (i, j) 좌표에 존재, k 번 움직이기 가능
    //      값 : 탈출 경우의 수
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        const int MOD = 1000000007;

        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));

        // 점화
        for (int move = 1; move <= maxMove; ++move) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    // 네 방향으로부터 경로를 더합니다.
                    long up = (i == 0) ? 1 : dp[move - 1][i - 1][j];
                    long down = (i == m - 1) ? 1 : dp[move - 1][i + 1][j];
                    long left = (j == 0) ? 1 : dp[move - 1][i][j - 1];
                    long right = (j == n - 1) ? 1 : dp[move - 1][i][j + 1];

                    // 현재 위치의 경로 수 계산
                    dp[move][i][j] = (up + down + left + right) % MOD;
                }
            }
        }

        return dp[maxMove][startRow][startColumn];
        
    }
};