class Solution {
public:


    // 최대 2회 거래를 할 때, 최대 이익은?
    // 연속으로 사거나 연속으로 팔수 없음.

    // 정답.
    // dp[k][i] : 최대 k번의 거래를 통해 i index 날까지 얻을 수 있는 최대 이익을 저장
    // 거래 횟수에 따른 상태 추적:
    //      거래 횟수가 증가할 때마다, 이전 거래 상태를 기반으로 현재 상태를 계산해야 한다.
    //      dp[k][i]를 계산하기 위해서는 dp[k-1][i-1](이전 거래에서의 상태)가 필요
    //      따라서 거래 횟수(k)와 날짜(i)를 모두 추적하려면 2차원 배열이 필요합니다.
    // 거래 횟수마다 다른 상태 유지:
    //      최대 k번의 거래를 모두 고려해야 하므로, 1부터 k까지 각 거래 횟수마다 다른 상태를 저장하고 갱신해야 한다.
    //      각 k에 대해 모든 i(날짜)를 고려해야 하므로, 2차원 dp 배열을 사용해 각 상태를 독립적으로 추적합니다.

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        vector<vector<int>> dp(3, vector<int>(n, 0));
        // k 가 0 일때는 이익이 0 이다.

        for (int k = 1; k <= 2; ++k) {

            int minPrice = prices[0]; // k번째 거래를 하기 위한 최소 매수 가격

            for (int i = 1; i < n; ++i) {
                minPrice = min(minPrice, prices[i] - dp[k-1][i-1]); // k번째 거래 시 최소 매수 가격 계산
                // prices[i] - dp[k-1][i-1] ...
                // 매수 타이밍을 잡기 위해서는..
                // 단순히 가장 최저가를 생각하기 보다는..
                // 이전 거래에서 얻은 최대 이익도 함께 고려해줘야한다.

                dp[k][i] = max(dp[k][i-1], prices[i] - minPrice);   // k번째 거래의 최대 이익 갱신
                // dp[k][i-1] : 이전날의 최대이익을 계승한다. (i index 날에는 아무것도 안함)
                // prices[i] - minPrice : i index 날에 매도한다. (계산된 최저가로..)
                //      prices[i] - (prices[prev] - dp[k-1][prev-1]) 로..
                //      prices[cur] - prices[prev] + dp[k-1][prev-1] 이 되는 것이다.
            }
        }

        return dp[2][n-1]; // 최대 2번 거래한 후 마지막 날까지의 최대 이익
    }
/*
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty()) return 0;

        // 거래 상태를 저장할 배열 초기화
        vector<int> buy(3, INT_MIN); // buy[k]는 k번째 매수 상태의 최대 이익
        vector<int> sell(3, 0);      // sell[k]는 k번째 매도 상태의 최대 이익

        // 주가 배열을 순회하며 buy와 sell 상태를 갱신
        for (int price : prices) {
            for (int k = 1; k <= 2; ++k) {  // 최대 두 번의 거래
                buy[k] = max(buy[k], sell[k - 1] - price); // k번째 매수 상태 갱신
                sell[k] = max(sell[k], buy[k] + price);    // k번째 매도 상태 갱신
            }
        }

        return sell[2]; // 최대 두 번의 거래 후 매도한 상태에서의 최대 이익
    }
*/

/*
    // 거래는 판매를 하면 +1 한다고 치겠다.
    // dp[i][k][0] : 현재, k번 거래함, i index까지 고려됨, 주식 없음
    // dp[i][k][1] : 현재, k번 거래함, i index까지 고려됨, 주식 있음

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // dp 배열 초기화
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));

        // 초기 조건 설정
        for (int k = 0; k <= 2; k++) {
            dp[0][k][0] = 0;                // 첫날에 매수 안함, 주식 없음
            dp[0][k][1] = -prices[0];       // 첫날에 매수한 경우
        }

        // 점화식 적용
        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= 2; k++) {
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);      // 주식 없음
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);    // 주식 있음
            }
        }

        return dp[n-1][2][0]; // 마지막 날에 k번의 거래를 완료한 상태에서 주식이 없는 최대 이익
    }
*/

};