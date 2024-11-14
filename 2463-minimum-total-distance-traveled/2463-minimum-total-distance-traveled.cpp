class Solution {
public:
    // robot 의 위치가 담긴 robot 배열 (위치 겹치지 않음)
    // factory[i] 에는 [공장 위치, 로봇 최대 수리가능 횟수] (위치 겹치지 않음)
    // 로봇과 공장의 위치는 겹치기 가능

    // 로봇은 모두 고장남. 한방향(음수 or 양수 방향)으로 움직임. (속도 동일)
    //      로봇은 서로 충돌하지 않음
    // 로봇이 수리가 되면 더이상 움직이지 않음

    // 모든 로봇의 이동거리 최소는?
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        // 위치 기반으로 정렬
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int n = robot.size();
        int m = factory.size();

        // 2차원 DP 배열 정의
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= m; i++) { // 각 공장에 대해..
            int position = factory[i - 1][0];
            int limit = factory[i - 1][1];
            
            // 현재 공장까지 로봇을 배치한 거리 최소값 구하기
            dp[i][0] = 0;  // 로봇을 배치하지 않는 경우 거리 0

            for (int j = 1; j <= n; j++) { // 모든 로봇 순회 (j : 현재 고려중인 로봇 수, 배치 완료된 로봇 수, 인덱스와 관련)
                dp[i][j] = dp[i - 1][j];  // 이전 공장에서 모든 로봇을 처리한 최소 거리
                long long sum_dist = 0;

                // 공장 i에 최대 limit까지 로봇 배치
                for (int k = 1; k <= limit && j - k >= 0; k++) { 
                    // k : 현재 공장에 배치 고려 중인 로봇 수, 인덱스와 관련
                    // 현재 공장에 배치할 로봇 수는 배치 완료된 로봇 수 보다 클 수 없음

                    sum_dist += abs(robot[j - k] - position); // j - k 로 계산해서 역순으로 해봄..
                    if (dp[i - 1][j - k] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + sum_dist);
                    }
                }
            }
        }

        return dp[m][n];
    }
};