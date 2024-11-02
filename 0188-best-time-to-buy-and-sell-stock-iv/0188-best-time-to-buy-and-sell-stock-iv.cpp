class Solution {
public:

    // 123. Best Time to Buy and Sell Stock III 과 동일함.

    // dp[k][i] : 현재, k 번째 거래완료, i index 날까지 고려
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        // k가 0이면, 거래를하지 않아 이익이 0이다.

        for (int g = 1; g <= k; g++) {

            int minPrice = prices[0];
            for (int i = 1; i < n; i++) {
                minPrice = min(minPrice, prices[i] - dp[g - 1][i - 1]);
                dp[g][i] = max(dp[g][i - 1], prices[i] - minPrice);
            }
        }

        return dp[k][n - 1];
    }
};