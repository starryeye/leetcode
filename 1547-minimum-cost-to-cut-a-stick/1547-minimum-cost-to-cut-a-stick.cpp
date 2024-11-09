class Solution {
public:

    // 길이가 n 인 "나무 자"를 자를 것이다.
    // 1회 절단 비용은 절단할 막대의 길이 (현재 절단할 막대의 길이)
    // 총 비용은 모든 절단 비용의 합계입니다.
    // 절단할 위치가 담긴 배열을 준다. (cuts)
    // 절단할 위치의 순서를 정해서 총 절단 비용의 최소 값 구하기.

    // dp[l][r]
    //      상태 : l index 부터 r index 까지 모두 절단 수행 (여기서의 index 는 cuts 의 index)
    //      값 : 최소 절단 비용
    // dp[l][r] = min(
    //                  dp[l][r],
    //                  dp[l][i - 1] + dp[i + 1][r] + (cuts[i + 1] - cuts[i - 1])
    //            )
    //
    // dp[l][i - 1] + dp[i + 1][r] + (cuts[i + 1] - cuts[i - 1]) 이 아니라
    // dp[l][i - 1] + dp[i + 1][r] + (cuts[r + 1] - cuts[l - 1]) 이 답이라고 한다. 이유는?
    // -> 문제를 잘 생각해보면..
    //      i 를 자르는 행위는 (l ~ i-1) 구간과 (i+1 ~ r) 구간 보다 "먼저" 수행되어야 한다.
    // 참고
    // 312. Burst Balloons 문제와 아주 유사하다.
    // -> 여기서는 i 가 "마지막"으로 터트리는거였음..
    int minCost(int n, vector<int>& cuts) {

        int m = cuts.size();
        
        // 절단 지점들을 정렬하고, 시작점과 끝점을 추가
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end()); // 값이 자를 위치이므로 자를 위치 순으로 정렬
        
        // DP 테이블 초기화
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        // 구간 길이를 점차 늘려가며 DP 테이블 채우기
        for (int len = 1; len <= m; ++len) {

            for (int l = 1; l <= m - len + 1; ++l) { // 양 끝점은 자르는 대상이 아니다.
                
                int r = l + len - 1;
                dp[l][r] = INT_MAX;
                
                for (int i = l; i <= r; ++i) {
                    dp[l][r] = min(
                        dp[l][r],
                        (dp[l][i - 1]) + (dp[i + 1][r]) + (cuts[r + 1] - cuts[l - 1])
                    );
                }
            }
        }

        return dp[1][m];  // 구간 [1, m]의 최소 절단 비용
    }
};