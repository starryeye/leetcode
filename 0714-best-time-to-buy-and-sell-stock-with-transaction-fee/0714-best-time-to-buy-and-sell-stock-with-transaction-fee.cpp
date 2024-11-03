class Solution {
public:

    // dp[i][0]
    //      상태 : i index 날 까지 고려, 주식 미보유
    //      값 : 최대 이익
    // dp[i][1]
    //      상태 : i index 날 까지 고려, 주식 보유
    //      값 : 최대 이익

    // 거래 : 사기만 해도 거래가 이루어진 것이다. (판매는 거래를 완료시키는 것이다.)
    //      따라서, 수수료는 매수 시점에 매기도록 하자.. (by 188)
    // 사실.. 수수료는 매도때 해도 되긴한다.
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = - prices[0] - fee;

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); // 아무것도 안함 or 매도
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee); // 아무것도 안함 or 매수
        }

        return dp[n - 1][0];
    }
};