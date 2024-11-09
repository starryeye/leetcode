class Solution {
public:

    // stations[i] = [position, fuel]
    //      i index 주유소가 position 에 존재, 연료는 fuel 리터 충전가능
    // 자동차의 연료 탱크는 무한이다.
    // 1마일당 1리터 소비
    // 주유소에 자동차가 도착하면 주유소에 있는 모든 연료를 챙김
    //      자동차의 연료가 0이 되면서 주유소에 도착하더라도 주유소의 연료를 챙기기 가능
    // 목적지에 도달할 수 없으면 -1을 반환.

    // 목적지 거리, 자동차 초기 연료, 주유소 정보 주어질때,
    //      자동차가 목적지에 도달하기 위해 거쳐야 하는 최소 재급유 정지 횟수를 반환.

    // 출발지에서 도착지까지 꼭 필요한 연료는 target 이다.
    // dp[i]
    //      상태 : 자동차가 i 에 존재
    //      값 : 재급유 횟수(최소)
    // -> 어려움.. 현재 남아있는 연료 추적이 어렵다..
    
    // 이문제는 greedy + priority queue 로 하면 O(n log n) 으로 가능하데..
    // 아래 dp 로 풀면.. O(n^2) 이다.

    // 정답
    // 0/1 knapsack problem 문제의 응용이다.
    // dp[k][i]
    //      상태 : k 개의 주유소 선택(배낭 무게), i index 까지 고려
    //      값 : 최대 가능 거리 (아이템 가치)

    // 참고
    // 점화식이.. 주유소 선택 개수를 제한한 거라서.. 조합 문제 점화식과 굉장히 유사하게 되었다.
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();

        if (target <= startFuel) return 0;
        if (n == 0) return target <= startFuel ? 0 : -1;

        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[0][i] = startFuel; // 주유소 0개 선택하면 startFuel 이 최대 가능 거리이다.
        }
        if (stations[0][0] <= startFuel) {
            dp[1][0] = dp[0][0] + stations[0][1]; // 1개 제한선택, 0 index 주유소 선택
        }

        // [1][1] 에서 시작하므로, 위에서 [0][0], [0][1], [1][0] 정도는 완성하고 시작해야겠다고 생각해야함
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i < n; i++) {

                if (stations[i][0] <= dp[k - 1][i - 1]) { // dp[k - 1][i - 1] 보다 dp[k][i - 1] 이 항상큼

                    dp[k][i] = max(dp[k][i - 1], dp[k - 1][i - 1] + stations[i][1]);
                    // dp[k][i - 1] : i index 주유소는 선택 X (이전에 이미 k개를 선택함)
                    // dp[k - 1][i - 1] + stations[i][1] : i index 주유소를 선택하여 급유함
                } else if (stations[i][0] <= dp[k][i - 1]) {
                    dp[k][i] = dp[k][i - 1];
                }
            }
        }

        for (int k = 0; k <= n; k++) {
            if (dp[k][n - 1] >= target) {
                return k;
            }
        }

        return -1;
    }
};