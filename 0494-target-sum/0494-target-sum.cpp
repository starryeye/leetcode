class Solution {
public:
    // target 에 도달할 수 있게 만드는 모든 수식 경우의 수
    // 0/1 knapsack problem 응용 문제
    // + or - 선택..
    //      -> 0/1 knapsack problem 문제는 원소들을 선택한다.
    //      -> 문제는.. 각 원소에 대해 + or - 를 선택하는 것이므로.. + 인 원소들을 선택? 이라고 생각할줄 알아야함
    //      -> 그래서. + 인 원소만 다 더하면 결국 진짜 target 은 뭐지?

    // 두 집합 P와 N을 각각 +가 붙은 집합과 -가 붙은 집합이라고 할 때
    // sum(P) - sum(N) = target 이다.
    // sum(P) + sum(N) = total sum 이므로
    // sum(P) * 2 - total sum = target 이다.
    // sum(P) = (target + total sum) / 2 이다.
    // -> 원소 합(무조건 +)이 (target + total sum) / 2 가 되는 부분집합 구하는 문제로 변함
    // -> 값의 범위를 봤을때 항상 음수가 아니다. (확인사항, 음의 index 는 없어야한다.)


    // dp[(target + total sum) / 2][i]
    //      상태 : 합이 (target + total sum) / 2 인 원소 집합, i index 까지 고려
    //      값 : 경우의 수

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 전체 합과 target을 더한 값이 홀수라면 정답이 될 수 없음
        if ((target + sum) % 2 != 0 || sum < abs(target)) return 0;

        int new_target = (target + sum) / 2;

        vector<vector<int>> dp(new_target + 1, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[0][i] = 1; // 합이 0인 경우는 항상 1가지는 존재 (공집합)
            if (nums[i] <= new_target) {
                dp[nums[i]][i] += 1; // 각 요소 스스로 도달할 수 있는 경우의 수 1 (nums[i] 가 0 이면 dp[0][i] 와 겹치므로 누적합으로 계산)
            }
        }

        for (int t = 0; t <= new_target; t++) {
            for (int i = 1; i < n; i++) {
                
                if (t >= nums[i]) {
                    dp[t][i] = dp[t][i - 1] + dp[t - nums[i]][i - 1]; // 선택을 하지 않거나 선택을 하거나 경우의수를 더함
                } else {
                    dp[t][i] = dp[t][i - 1]; // 선택을 하지 않는 경우 밖에 없음
                }
            }
        }


        return dp[new_target][n - 1];
    }
};