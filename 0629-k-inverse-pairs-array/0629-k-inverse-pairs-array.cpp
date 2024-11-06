class Solution {
public:
    // 역쌍 : index 는 오름 차순인데 값은 내림차순인 경우이다.
    // [1, 3, 2] -> [3, 2] 가 역쌍이다. 나머지는 모두 역쌍이 아님 -> k = 1
    // [2, 1, 3] -> [2, 1] 이 역쌍이다. 나머지는 모두 역쌍이 아님 -> k = 1


    // dp[i][k]
    //      상태 : i 숫자까지 고려, k 개의 역쌍을 가짐
    //      값 : 경우의 수
    // dp[i][k] = dp[i - 1][k] + dp[i - 1][k - 1] + dp[i - 1][k - 2] + ... + dp[i - 1][k - (i - 1)]
    // dp[i - 1][k] : i-1 index 까지 사용되었고 역쌍이 k개 라면 i 를 가장 뒤에 추가하면 됨.
    // dp[i - 1][k - 1] : i-1 index 까지 사용되었고 역쌍이 k-1개 라면 i 를 i-1 index 자리로 끼워 넣기 -> 1개가 추가로 생성됨
    // ...

    // 위 식을 최적화할 수 있다.
    // dp[i][k] = dp[i][k - 1] + dp[i - 1][k] ???????? 왜??
    int kInversePairs(int n, int k) {

        const int MOD = 1000000007;
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // k = 0일 때는 어떤 숫자 i를 사용하더라도 역쌍이 0인 경우의 수는 1개
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // 점화식 계산
        for (int i = 1; i <= n; i++) {
            for (int g = 1; g <= k; g++) {
                dp[i][g] = (dp[i][g - 1] + dp[i - 1][g]) % MOD;
                
                // g >= i 인 경우 dp[i - 1][g - i] 값을 빼줘서 중복을 방지..?
                if (g >= i) {
                    dp[i][g] = (dp[i][g] - dp[i - 1][g - i] + MOD) % MOD;
                }
            }
        }

        return dp[n][k];
    }
};