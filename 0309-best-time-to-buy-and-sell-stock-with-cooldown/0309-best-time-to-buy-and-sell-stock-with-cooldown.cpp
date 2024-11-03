class Solution {
public:
    // dp[i][0] : i index 날까지 고려, 주식 미보유
    // dp[i][1] : i index 날까지 고려, 주식 보유
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        if (n == 0 || n == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(2, 0));

        // 0 번째 날
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        // 1 번째 날
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]); // 아무것도 안함 or 매도
        dp[1][1] = max(dp[0][1], dp[0][0] - prices[1]); // 아무것도 안함 or 매수(하루 안 쉬어도 됨)

        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); // 아무것도 안함 or 매도
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]); // 아무것도 안함 or 매수(하루 쉬도록함)
        }

        return dp[n - 1][0];
    }
};