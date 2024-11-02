class Solution {
public:
    // 무한대로 사고 팔수 있을때.. 최대 이익은?

    // dp[i][0] : i index 날에 주식이 없는 경우, 최대 이익
    // dp[i][1] : i index 날에 주식이 있는 경우, 최대 이익
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;           // 0 index 날에 주식이 없으면 이익은 0
        dp[0][1] = - prices[0]; // 0 index 날에 주식이 있으면 이익은 -prices[0]

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // dp[i - 1][0] 선택 : 그 전날에도 없었고 현재날에도 없다. (아무 것도 안함)
            // dp[i - 1][1] + prices[i] 선택 : 그 전날에 보유하고 있던 주식을 현재가에 판다.

            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            // dp[i - 1][1] 선택 : 그 전날에도 있었고 현재날에도 있다. (아무 것도 안함)
            // dp[i - 1][0] - prices[i] 선택 : 그 전날에는 없었는데 현재가에 주식을 샀다.
        }

        return dp[n - 1][0];
    }

    /*
        사실..
        dp[i - 1][0], dp[i - 1][1] 만 변수로 관리하면 되기 때문에
        dp 배열이 필요 없다.
    */
};