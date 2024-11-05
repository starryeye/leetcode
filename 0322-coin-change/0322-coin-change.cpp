class Solution {
public:
    // dp[k]
    //      상태 : 원소의 합이 k
    //      값 : 원소 갯수 최소값
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0; // 원소의 합이 0 인 경우엔 사용된 코인 0
        for (int i = 0; i < n; i++) {

            if (amount >= coins[i]) {
                dp[coins[i]] = 1; // 스스로 만들수 있으면 최소 1
            }
        }

        for (int k = 1; k <= amount; k++) {
            for (int i = 0; i < n; i++) {

                if (k - coins[i] >= 0 && dp[k - coins[i]] != INT_MAX) { // 값 유효성
                    dp[k] = min(dp[k], dp[k - coins[i]] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};