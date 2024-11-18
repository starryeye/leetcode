class Solution {
public:
    // piles
    //      상태 : 짝수개의 돌더미
    //      값 : 더미에 존재하는 돌 갯수는 홀수

    // alice, bob
    // alice 가 먼저 작업 시작하고 번갈아가며 진행
    // 작업
    //      돌더미 배열 양끝에서 돌더미를 다 가진다.(돌 갯수 만큼 점수 획득)
    // alice 가 이기면 true

    // dp[i][j]
    //      상태 : [i ~ j] 범위에서 작업 진행
    //      값 : 얻을 수 있는 최대 점수 차이
    // piles[i] 를 선택 : piles[i] - dp[i + 1][j]
    //                      piles[i] : 작업자가 점수를 얻어서 차이를 냄.
    //                      - dp[i + 1][j] : 다음 작업자가 점수를 얻어서 차이를 좁힘.
    // piles[j] 를 선택 : piles[j] - dp[i][j - 1]
    //                      piles[j] : 작업자가 점수를 얻어서 차이를 냄.
    //                      - dp[i][j - 1] : 다음 작업자가 점수를 얻어서 차이를 좁힘.

    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // 초기화
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i]; // alice 혼자 선택하면 점수차이는 piles 그자체
        }

        // 점화
        for (int len = 2; len <= n; ++len) { // 구간 길이

            for (int i = 0; i <= n - len; ++i) { // 시작점 i
                int j = i + len - 1; // 끝점 j

                dp[i][j] = max(
                    piles[i] - dp[i + 1][j],
                    piles[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] > 0;
    }
};