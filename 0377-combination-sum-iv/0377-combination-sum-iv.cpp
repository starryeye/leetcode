class Solution {
public:

/*
    // 0/1 knapsack problem 응용
    // -> 0/1 knapsack problem 은 각 원소를 선택하던 안하던인데..
    // 이 문제는 각 원소를 중복 선택이 가능하다...

    // dp[k][i]
    //      상태 : 원소 총합이 k, i index 까지 고려
    //      값 : 경우의 수

    // 점화식
    // dp[k][i] = dp[k][i - 1] + dp[k - nums[i]][i]
    //      dp[k][i - 1] : i index 원소를 선택하지 않은 경우의 수
    //      dp[k - nums[i]][i] : i index 원소를 선택한 경우의 수
    //              각 원소를 한번만 선택(0/1)하는 경우일 땐, dp[k - nums[i]][i - 1] 로 계산하지만..
    //              dp[k - nums[i]][i] 로 계산하여... i index 원소를 중복 선택해도 되도록 한다.
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<vector<int>> dp(target + 1, vector<int>(n, 0));

        // 초기화
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1; // 합이 0 인 경우(공집합)
        }
        for (int k = 1; k <= target; k++) { // i 가 0 인 경우
            if (k >= nums[0]) {
                dp[k][0] = dp[k - nums[0]][0];
            }
        }

        // 점화
        for (int k = 1; k <= target; k++) {
            for (int i = 1; i < n; i++) {
                
                if (k >= nums[i]) {
                    dp[k][i] = dp[k][i - 1] + dp[k - nums[i]][i];
                } else {
                    dp[k][i] = dp[k][i - 1];
                }
            }
        }

        return dp[target][n - 1];
    }
*/

// 위 방법으로는 답이 자꾸 안나와서..
// 아래와 같이 생각하자.. 훨씬 쉽다..

    // dp[k] : 원소의 합이 k 가 되는 경우의 수
    int combinationSum4(vector<int>& nums, int target) {

        vector<unsigned long long> dp(target + 1, 0); // dp 배열을 unsigned long long 타입으로 정함. (input 값이 너무 큼)
        dp[0] = 1; // 합이 0일 때 경우의 수는 1 (아무것도 선택하지 않는 경우)

        // DP 배열 채우기
        for (int k = 1; k <= target; k++) {
            for (int i = 0; i < nums.size(); i++) {

                if (k >= nums[i]) {
                    dp[k] += dp[k - nums[i]];
                }
            }
        }

        return static_cast<int>(dp[target]);
    }
};