class Solution {
public:
    // 단 1회 거래를 할때 최대 이익은?

    // dp[i] : i index 날에 최대 이익
    // -> dp[i] : i index 날에 매도 했을때 최대 이익

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        if (n == 0) {
            return 0;
        }
    
        vector<int> dp(n, 0); // dp[i] : i번째 날에 매도했을 때 최대 이익을 저장
        int minPrice = prices[0];
    
        for (int i = 1; i < n; ++i) {
            
            dp[i] = prices[i] - minPrice;
            // i번째 날에 매도했을 때 최대 이익 계산
            // prices[i] - minPrice : 현재 가격에 지금까지의 최저 가격을 뺀 가격
            
            minPrice = min(minPrice, prices[i]); // 최저 주가 찾기 위해서 for(j : 0 ~ i-1) 돌릴 수도..
            // 최저 주가 갱신
        }
    
        return *max_element(dp.begin(), dp.end());
    }

    /*
        사실..
        dp[i] = prices[i] - minPrice; 를
        dp[i] = max(dp[i - 1], prices[i] - minPrice); 로 변경하면 dp[n-1] 이 답이된다.

        사실..
        dp[i - 1] 을 하나의 변수로 써도 문제가 풀리기 때문에
        dp 배열이 필요없다.
    */
};