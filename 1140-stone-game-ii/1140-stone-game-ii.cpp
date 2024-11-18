class Solution {
public:
    // piles
    //      상태 : 돌더미
    //      값 : 더미에 존재하는 돌 갯수

    // alice, bob
    // alice 가 먼저 작업 시작하고 번갈아가며 진행
    // 작업
    //      첫번째 돌무더기 부터 X 개의 돌무더기를 가져갈 수 있고, 1 <= X <= 2M 를 만족한다.
    //          M = max(M, X) 로 업데이트하고 다음 사람에게 차례를 넘긴다. 최초 alice 턴에는 M = 1
    // alice 의 최대 점수 리턴..

    // dp[i][M]
    //      상태 : alice 가 i 부터 시작하고 M 값이 주어짐.
    //      값 : 최대 점수
    int stoneGameII(vector<int>& piles) {

        int n = piles.size();
        
        // suffixSum[i]: i부터 끝까지 돌 더미의 합
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // dp[i][M]: i부터 시작하고 M 크기 기준으로 최대 점수
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // DP 계산
        for (int i = n - 1; i >= 0; --i) {  // 인덱스 역순 순회

            for (int M = 1; M <= n; ++M) {  // 현재 M 값

                for (int X = 1; X <= 2 * M; ++X) {  // 가져갈 수 있는 모든 돌 무더기 갯수 순회
                    
                    if (i + X < n) {
                        dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + X][max(M, X)]);
                        // 877. Stone Game 과 동일하게.. 여기서도
                        // - dp[i + X][max(M, X)] 은.. bob이 최적으로 플레이한 점수
                        // 그러면 alice 혼자 다 가질때의 점수(suffixSum[i]) 에서
                        // bob이 최적으로 플레이한 점수를 빼면 alice 의 점수임.
                    } else if (i + X == n) { // 맨마지막에서 시작하면 1개만 남았으므로 무조건 다 가져감..
                        dp[i][M] = max(dp[i][M], suffixSum[i]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};