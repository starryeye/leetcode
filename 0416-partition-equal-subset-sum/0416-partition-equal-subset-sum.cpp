class Solution {
public:
    // 0/1 knapsack problem 응용
    // nums 의 전체 원소 합이 sum 이라면
    // sum / 2 값을 만드는 부분배열이 있다면.. 
    //      자연스럽게 해당 부분배열에 포함되지 않은 원소들의 합도 sum / 2 이다.

    // dp[k][i]
    //      상태 : i index 까지 고려, 원소 합 k
    //      값 : true or false
    //      정답 : dp[n - 1][sum / 2]

    // dp[k][i] = dp[k][i - 1] || dp[k - nums[i]][i - 1]
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0); // include numeric
        int n = nums.size();

        // 전체 합이 홀수면 두 부분으로 나눌 수 없음
        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<bool>> dp(target + 1, vector<bool>(n, false));
        // 초기화
        for (int i = 0; i < n; i++) {
            dp[0][i] = true; // 합이 0인 부분배열은 항상 만들수 있다. (공집합)
            if (nums[i] <= target) { // 전체 배열이 [100, 2] 이면 dp 범위를 초과하는 곳에 집어넣으려 하기때문
                dp[nums[i]][i] = true; // 자기 자신은 해당 i index 까지 고려되면 항상 true
            }  
        }

        for (int k = 0; k <= target; k++) {
            for (int i = 1; i < n; i++) {

                if (k - nums[i] >= 0) {
                    dp[k][i] = dp[k][i - 1] || dp[k - nums[i]][i - 1];
                    // dp[k][i - 1] : i index num 을 선택하지 않는다.
                    // dp[k - nums[i]][i - 1] : i index num 을 선택한다.
                    // 두 중 하나만 true 라도 dp[k][i] 는 true
                } else {
                    dp[k][i] = dp[k][i - 1];
                }
            }
        }

        return dp[target][n - 1];
    }
};