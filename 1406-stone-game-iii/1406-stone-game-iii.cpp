class Solution {
public:
    // stoneValue
    //      상태 : 돌더미
    //      값 : 더미에 존재하는 돌 갯수

    // alice, bob
    // alice 가 먼저 작업 시작하고 번갈아가며 진행
    // 작업
    //      첫번째 돌무더기부터 가져갈 수 있다. 무더기 갯수는 1, 2, 3개로 가져갈 수 있음.
    //          돌의 갯수가 곧 점수가 된다.
    // 둘다 최적의 플레이를 할때..

    // alice 가 이기면, alice
    // bob 이 이기면, bob
    // 비기면, tie

    // dp[i]
    //      상태 : 남아있는 돌이 stoneValue[i:] 이다.
    //      값 : 현재 차례 플레이어가 얻을 수 있는 최대 점수 차이
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();
        
        vector<int> dp(n + 1, 0); // dp[i]: stoneValue[i:]에서의 점수 차이
        // dp[n] = 0, 남아있는 돌이 없을때 얻을 수 있는 최대 점수차이 0

        // 역순으로 DP 계산
        for (int i = n - 1; i >= 0; --i) {

            dp[i] = INT_MIN;
            
            int currentSum = 0;

            // 최대 1, 2, 3개의 돌을 가져가는 경우 계산
            for (int x = 1; x <= 3; ++x) { // 가지고 갈 수 있는 돌무더기 갯수 순회
                if (i + x <= n) { // 경계
                    currentSum += stoneValue[i + x - 1]; // 돌갯수 계산
                    dp[i] = max(dp[i], currentSum - dp[i + x]);
                    // stone game 1, 2 와 같이..
                    // currentSum (현재 플레이어가 얻을 수 있는 점수) 에서
                    //      dp[i + x] (다음 플레이어가 얻을 수 있는 최대 점수) 를 뺀다.
                }
            }
        }

        // 결과 판단
        if (dp[0] > 0) 
            return "Alice";
        if (dp[0] < 0) 
            return "Bob";
        
        return "Tie";
    }
};