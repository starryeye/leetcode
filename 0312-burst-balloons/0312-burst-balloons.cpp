class Solution {
public:
    // n개의 풍선배열, 값은 풍선에 쓰여진 숫자
    // i index 풍선 터트리면, i-1, i, i+1 index 풍선 숫자의 곱을 획득
    // 풍선을 터트리면 없어진 풍선 만큼 축약 (터트린 풍선만 없어짐 양쪽 풍선은 산다.)
    // 풍선 배열의 범위를 벗어나면, 벗어난 풍선(가상의 풍선)의 숫자는 1로 생각 하면 된다.

    // dp[k][i]
    //      상태 : i index 풍선을 지금 터트릴것임(포함), i index 풍선은 k 번째로 터트려짐
    //      값 : 점수 최댓값
    // -> 이렇게 하면 너무 어려움.
    // -> k번에 i번째 풍선을 터뜨릴 때, 어떤 풍선들이 남아있고, 양쪽에 있는 풍선의 값이 무엇인지 추적이 어려울 듯..

    // 정답
    //  dp[left][right]
    //      상태 : left에서 right까지의 구간 풍선을 모두 터뜨림
    //      값 : 최대 점수
    // 각 구간에서 마지막으로 터뜨리는 풍선을 i로 선택했을 때, 
    //      그 구간의 코인 수는 left에서 right까지 구간 중 i를 마지막으로 터뜨리는 경우로 나뉜다.
    //      즉, dp[left][right] = 
    //          max(
    //              dp[left][right], 
    //              dp[left][i - 1] + dp[i + 1][right] + nums[left - 1] * nums[i] * nums[right + 1]
    //              // dp[left][i - 1] : left ~ i-1 구간 모두 터트리고 최대값
    //              // dp[i + 1][right] : i+1 ~ right 구간 모두 터트리고 최대값
    //              // nums[left - 1] * nums[i] * nums[right + 1] : i index 풍선 터트림
    //              //          left-1 : left ~ i-1 구간 모두 터트렸으므로 left-1 index 가 i index 옆에 존재하게됨
    //          )로 계산됨
    //      여기서 nums[i]는 left와 right 사이에서 마지막으로 터뜨리는 풍선

    // 백준 11049. 행렬 곱셈 순서 문제와 유사
    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        
        // 양 끝에 가상의 풍선 1을 추가
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            balloons[i + 1] = nums[i];
        }

        // DP 테이블 생성
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // 구간 길이를 점차 늘려가며 DP 테이블 채우기 (구간 길이가 1이면, l == r)
        for (int length = 1; length <= n; ++length) {

            for (int left = 1; left <= n - length + 1; ++left) {
                int right = left + length - 1;

                for (int i = left; i <= right; ++i) {
                    // left에서 right까지의 구간에서 i를 마지막으로 터뜨릴 때 최대 코인 수 계산
                    dp[left][right] = max(
                        dp[left][right],         
                        (dp[left][i - 1]) + (balloons[left - 1] * balloons[i] * balloons[right + 1]) + (dp[i + 1][right])
                    );
                }
            }
        }
        
        // 전체 구간의 최대 코인 수 반환
        return dp[1][n];
    }
};