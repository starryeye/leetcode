class Solution {
public:

    // alice, bob
    // alice 가 먼저 작업 시작하고 번갈아가며 진행

    // n 개의 돌들이 주어진다.

    // 작업
    //      각 플레이어의 차례에 해당 플레이어는 더미에서 0이 아닌 제곱 수의 돌을 제거하는 동작을 수행
    //      어떤 플레이어의 차례에 더이상 돌이 존재하지 않아 돌을 제거할 수 없다면 진다.

    // alice 가 이기면 true 반환

    // dp[i]
    //      상태 : i개의 돌이 남았다.
    //      값 : 현재 차례의 플레이어가 무조건 이기면 true, 무조건 지면 false
    bool winnerSquareGame(int n) {
        
        vector<bool> dp(n + 1, false);
        // dp[0] = false, 돌이 0개 남았으면 현재 차례의 플레이어가 진다.

        for (int i = 1; i <= n; i++) {

            for (int k = 1; k * k <= i; k++) {
                int square_number = k * k; // 가능한 제곱수 계산
                
                if (dp[i - square_number] == false) {
                    dp[i] = true;
                    break;

                    // dp[i - square_number] == false
                    //      alice 가 square_number 만큼 가져가면..
                    //      bob 은 i-square_number 만큼 남고..
                    //          dp[i - square_number] 가 false 의미는
                    //              bob 이 무조건 진다는 의미임
                    //              따라서, dp[i] 는 무조건 이기기 때문에 true.. (더이상 탐색은 불필요하므로 break)
                }
            }
        }

        return dp[n];
    }
};