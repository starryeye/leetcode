class Solution {
public:
/*
    // 123. Best Time to Buy and Sell Stock III 과 동일함.

    // dp[k][i] : 현재, k 번째 거래완료, i index 날까지 고려 최대 이익
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
*/
    /*
    // 1차원 배열로 최적화 가능..
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        vector<int> dp(n, 0);
    
        for (int g = 1; g <= k; g++) {
            int minPrice = prices[0];
            int prev = 0; // dp[g-1][i-1]를 저장하기 위한 변수
            for (int i = 1; i < n; i++) {
                int temp = dp[i]; // 현재 dp[i]를 임시로 저장 (다음 i를 위해 prev 업데이트)
                minPrice = min(minPrice, prices[i] - prev);
                dp[i] = max(dp[i - 1], prices[i] - minPrice);
                prev = temp; // dp[g-1][i-1] 업데이트
            }
        }

        return dp[n - 1];
    }
    */

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        // dp[k][i][0] : k번 거래 완료, i index 날까지 고려, 주식 보유X 최대 이익
        // dp[k][i][1] : k번 거래 완료, i index 날까지 고려, 주식 보유O 최대 이익
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n, vector<int>(2)));

        // 초기화
        for (int g = 0; g <= k; g++) {
            dp[g][0][0] = 0; // 0 index 에 주식 보유 X -> 이익 0
            dp[g][0][1] = -prices[0]; // 0 index 에 주식 보유 O -> 이익 -prices[0]
        }
        
        // 점화
        // for 문의 순서는 상관 없는듯?
        for (int g = 1; g <= k; g++) {
            for (int i = 1; i < n; i++) {
                dp[g][i][0] = max(dp[g][i - 1][0], dp[g][i - 1][1] + prices[i]); // 아무것도 안함 or 매도
                dp[g][i][1] = max(dp[g][i - 1][1], dp[g - 1][i - 1][0] - prices[i]); // 아무것도 안함 or 매수
            }
        }

        return dp[k][n-1][0];
    }
};