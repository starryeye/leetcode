class Solution {
public:

    // n개의 집이 줄지어 있고,
    // 각 집은 m가지 색상 중 하나로 칠할 수 있다.

    // 집집마다 특정 색상으로 칠하는 비용은 다르다.
    // 인접한 두 집이 같은 색이 되지 않도록 모든 집을 칠해야 함.

    // costs[i][k]
    //      i 번째 집을 m가지 색상 중 k번째 색상으로 칠하는데 드는 비용

    // 모든 집을 칠할때 드는 최소비용 구하기.

    int minCostII(vector<vector<int>>& costs) {

        if (costs.empty()) return 0;

        int n = costs.size();
        int m = costs[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // 초기화
        for (int k = 0; k < m; k++) {
            dp[0][k] = costs[0][k];
        }

        // DP 계산
        for (int i = 1; i < n; ++i) {

            // 이전 행에서 최소값과 두 번째 최소값 계산
            int min_first = INT_MAX;
            int min_second = INT_MAX;
            int min_first_index = -1;

            // 이전 행에서 최솟값(+인덱스), 두번째 최솟값 찾기
            for (int k = 0; k < m; ++k) {
                if (dp[i - 1][k] < min_first) {
                    min_second = min_first;
                    min_first = dp[i - 1][k];
                    min_first_index = k;
                } else if (dp[i - 1][k] < min_second) {
                    min_second = dp[i - 1][k];
                }
            }

            // 현재 행 계산
            for (int k = 0; k < m; ++k) {
                if (k == min_first_index) {
                    dp[i][k] = costs[i][k] + min_second; // 동일 색인 경우 두 번째 최소값 사용
                } else {
                    dp[i][k] = costs[i][k] + min_first; // 다른 색인 경우 최소값 사용
                }
            }
        }

        // 마지막 행에서 최소 비용
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};