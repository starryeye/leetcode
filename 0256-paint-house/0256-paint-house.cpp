class Solution {
public:

    // n개의 집이 줄지어 있고,
    // 각 집은 빨간색, 파란색, 녹색의 세 가지 색상 중 하나로 칠할 수 있다.

    // 집집마다 특정 색상으로 칠하는 비용은 다르다.
    // 인접한 두 집이 같은 색이 되지 않도록 모든 집을 칠해야 함.

    // costs[i][3]
    //      i 번째 집을 특정 색상(3가지 색상 중 하나)으로 칠하는데 드는 비용

    // 모든 집을 칠할때 드는 최소비용 구하기.

    // dp[i][3]
    //      상태 : i 번째 집을 특정 색상으로 칠함.
    //      값 : 최소 비용
    int minCost(vector<vector<int>>& costs) {

        if (costs.empty()) return 0;

        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));

        // 초기화
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        // DP 계산
        for (int i = 1; i < n; ++i) {
            dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }

        // 결과 반환
        return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};