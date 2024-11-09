class Solution {
public:

    // 정수 배열 nums와 정수 k가 주어진다.
    //      nums를 k개의 비어 있지 않은 연속부분 배열로 분할
    //      연속부분 배열이 여러개로 나오면, 그 배열중 원소최대합이 최소화되도록 한다.
    // 그 값을 구하라..

    // dp[k][i]
    //      상태 : k개로 분할, i index 를 고려(포함)
    //      값 : 연속부분 배열이 여러개로 나오면, 그 배열중 원소최대합의 최솟값

    // dp[k][i] = min(dp[k][i], dp[k - 1][j - 1], j ~ i 까지 합)


    // - > 1335. Minimum Difficulty of a Job Schedule 문제 유형과 동일하다..
    // 해당 문제를 이해하면 풀줄알게됨
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();

        if (n < k) return -1;

        vector<vector<int>> dp(k, vector<int>(n, INT_MAX));

        // 편의상 k = 0 index 이면 (문제에서 정의한 k, 한개로 나눔으로 하겠다. 즉, 전체배열 그자체)
        // -> 그래서 이제 칼을 사용한 횟수가 됨
        // 초기화
        dp[0][0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + nums[i];
        }

        for (int split = 1; split < k; split++) {

            // i index 까지면 총 i + 1 개이다.
            // split + 1 <= i + 1 이어야 말이됨
            for (int i = split; i < n; i++) {

                int localArraySum = 0;

                for (int j = i; j >= split; j--) {
                    
                    localArraySum += nums[j]; // j ~ i 까지 원소합

                    int currentArraysMaxSum = max(localArraySum, dp[split - 1][j - 1]);
                    // j ~ i 까지 원소합을..
                    //      칼을 split-1 만큼 사용했고, j-1 index 까지 고려된 값과 비교해서
                    // 최댓값
                    
                    dp[split][i] = min({dp[split][i], currentArraysMaxSum});
                    // dp 에는 최솟값 갱신
                }
            }
        }

        return dp[k - 1][n - 1];
    }
};