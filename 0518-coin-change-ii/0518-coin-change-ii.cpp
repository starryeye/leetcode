class Solution {
public:

    // 각 원소를 중복으로 선택이 가능하며, "조합" 문제이다..

    // dp[k]
    //      상태 : 원소의 합이 k
    //      값 : 경우의 수
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        vector<unsigned long long> dp(amount + 1, 0);

        dp[0] = 1; // 합이 0인 동전 조합의 경우의 수 1 (공집합)

        // 아래와 같이 계산하면.. 조합문제가 아닌 순열 문제가 되어버린다. [1, 2] 와 [2, 1] 을 서로 다른 것으로 카운팅
        // -> 377. Combination Sum IV
        /*
        for (int k = 1; k <= amount; k++) {
            for (int i = 0; i < n; i++) {
                if (k - coins[i] >= 0) {
                    dp[k] += dp[k - coins[i]];
                }
            }
        }
        */

        // 위와 다른점은 for 문의 내/외부가 바뀌었다..
        // 외부 반복문을 coins 에 대해 실행될 때, 각 동전은 독립적으로 처리됨.
        // coins[0] 으로 만들 수 있는 모든 경우를 계산 후, coins[1] 로 만들 수 있는 모든 경우를 계산..
        // [1, 2] 와 [2, 1] 은 동일한 것으로 카운팅된다. 
        // -> 1에 대해 모든 경우를 보고 2로 넘어 가기 때문에 [2, 1] 은 계산되지 않음
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= amount; k++) {
                if (k - coins[i] >= 0) {
                    dp[k] += dp[k - coins[i]];
                }
            }
        }

        return static_cast<int>(dp[amount]);
    }

    // 참고
    // N개 중 K개를 선택하는 경우의 수에서
    // dp[i][k]
    //      상태 : i index 까지 고려, k개 선택함
    //      값 : 경우의 수
    // 이 방식을 생각한다면..
    // dp[i][k] : i index 까지 고려, k (amount) 의 경우의수에서 응용되었다고 볼 수 있다.
};