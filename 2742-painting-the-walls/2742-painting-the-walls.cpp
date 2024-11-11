class Solution {
public:
    // n 개의 서로 다른 벽을 각각 칠하는 데 소요되는 비용과 시간 배열이 각각 주어짐

    // 유료 기술자
    //      i index 벽을 칠하는데 time[i] 시간만큼 걸리고 cost[i] 만큼 비용 필요
    // 무료 기술자
    //      i index 벽을 칠하는데 무조건 1시간 걸리고 공짜이다.
    //      유료 기술자가 일하고 있을때만 일함

    // 모든 벽을 칠하는데 지불해야할 최소 비용은?

    // 0/1 knapsack problem 응용이다.
    // dp[k][i]
    //      상태 : k개의 벽을 칠함, i index 까지 고려
    //      값 : 지불해야할 최소 비용

    // dp[k][i] = min(dp[k][i - 1], dp[k - (time[i] + 1)][i - 1] + cost[i])
    // dp[k][i - 1] : i index 벽을 선택(유료 작업자가 선택)하지 않음
    // dp[k - (time[i] + 1)][i - 1] + cost[i] : i index 벽을 선택함
    //      i index 벽을 유료 작업자가 선택하면.. 무료 작업자는 time[i] 만큼 벽을 칠할 수 있다.
    //      최종적으로 time[i] + 1 만큼 무료 작업자와 유료작업자가 벽을 칠하게됨.
    //
/*
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int n = cost.size();

        vector<vector<int>> dp(n + 1, vector<int>(n, INT_MAX));

        // 초기화: 벽을 하나도 칠하지 않을 때 비용은 0
        // [1][1] 로 시작하므로 [0][1], [1][0], [0][0] 초기화 해야함
        for (int i = 0; i < n; ++i) {

            dp[0][i] = 0; 
            // 0개의 벽을 칠하면 비용은 0
            
            dp[i][0] = cost[0]; 
            // i개의 벽을 칠하는데 0 index 만 고려하면 무조건 선택해서 칠해야한다..
            //      이부분이 받아드리기 어려우면.. index 로 생각하지말고 "번째" 로 생각해보자..
            //          그러면 dp[i][0] 의 의미에서 dp[i][1] 으로 되고.. 
            //          dp[i][0] 은 "0번째 벽" 즉.. 벽을 선택하지 않은 것이고..
            //          이때의 값은 무한대로 초기화 하므로 dp[i][1] 은 무조건 cost[0] 으로 초기화 해야함..
        }

        // 점화
        for (int k = 1; k <= n; k++) {

            for (int i = 1; i < n; i++) {

                dp[k][i] = dp[k][i - 1]; 
                // dp[k - (time[i] + 1)][i - 1] 이 INF 일경우도 생길 수 있어서 무조건 초기화 해줘야함..
                //      그냥 그 조건문을 없애자니.. 최종 답이 -1 로도..

                if (k - (time[i] + 1) >= 0) { // 경계값 검사
                    if (dp[k - (time[i] + 1)][i - 1] != INT_MAX) { // 경계값 벗어나는지 체크

                        dp[k][i] = min(dp[k][i], dp[k - (time[i] + 1)][i - 1] + cost[i]);
                    }
                }
            }
        }

        return dp[n][n - 1] == INT_MAX ? -1 : dp[n][n - 1];
    }
*/

    // 위 방법으로 어느정도 테스트 케이스가 통과 되는데.. 완벽하게 정답이 안나옴..
    // 아래는..
    // dp[j]
    //      상태 : 벽 j 개를 칠함.
    //      값 : 최소 비용
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int n = cost.size();

        vector<int> dp(n + 1, 1e9);
        
        dp[0] = 0;

        for (int i = 0; i < n; ++i) { // i index 까지 고려
            
            for (int j = n; j > 0; --j) { // 벽 갯수

                int prevWallCount = max(j - (time[i] + 1), 0);

                dp[j] = min(dp[j], dp[prevWallCount] + cost[i]);
            }
        }
            
                
        return dp[n];
    }
};