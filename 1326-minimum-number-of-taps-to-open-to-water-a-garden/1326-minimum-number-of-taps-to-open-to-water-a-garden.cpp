class Solution {
public:
    // 전체 정원에 물을 공급하기 위해 열려야 하는 최소 수도꼭지 수를 반환
    //      정원에 물을 줄 수 없는 경우 -1을 반환

    // 정수 n, n+1 길이의 ranges 정수 배열이 주어짐.
    // ranges[i] 값은 [i - ranges[i] ~ i + ranges[i]] 범위를 커버한다는 의미 이다.
    // (0 ~ n) 범위를 커버하도록 ranges index 를 선택할때.. 최소 index 갯수(최소 탭 수)는?

    // dp 로 풀면 O(n^2) 이고 greedy 로 풀면 O(n) 이다..

    // dp[i] 
    //      상태 : 위치 0에서 위치 i까지 정원에 물을 줌.
    //      값 : 최소 탭 수

    // 각 탭에 대해 범위를 알 수 있다.
    //      left = max(0, i - ranges[i])
    //      right = min(i + ranges[i], n)
    int minTaps(int n, vector<int>& ranges) {

        // DP 배열 초기화
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0; // 위치 0에서 위치 0까지 정원에 물을 줌.
        // 길이가 0인 정원이므로 물을 줄필요 없어서 0

        // 각 수도꼭지의 범위를 기반으로 DP 갱신
        for (int j = 0; j <= n; ++j) {

            int left = max(0, j - ranges[j]);
            int right = min(j + ranges[j], n);

            // left ~ right 까지 커버하려면 현재 j 탭만 누르면 된다.

            for (int i = left; i <= right; ++i) { // left <= i <= right
                
                if (dp[left] != INT_MAX) {

                    dp[i] = min(dp[i], dp[left] + 1);
                    // dp[i] : 정원 [0, i]를 덮기 위해 필요한 최소 수도꼭지 개수.
                    // dp[left] + 1 : left 지점까지 덮기 위해 필요한 수도꼭지 수 + 현재 j 수도꼭지
                }
            }
        }

        // 정원을 덮을 수 없는 경우
        if (dp[n] == INT_MAX) return -1;

        // 수도꼭지 최소 개수 반환
        return dp[n];
    }
};