class Solution {
public:

    // house[i] : 거리를 따라 있는 i번째 집의 위치
    // 거리에 정수 k개의 사서함을 할당
    // 각 집에서 가장 가까운 사서함의 거리 총합 의 최소값

    // cost[l][r] : (l ~ r) 구간 집을 한 구간으로 보고, 그 구간에 우체통을 하나 설치했을 때의 최소 비용
    //                  구간의 중앙 위치에 우체통을 설치했을 때 최소가 됨.
    // dp[i][k]
    //      상태 : i index 까지 고려, 사서함 k 개 설치
    //      값 : 거리 총합 (최소)
int minDistance(vector<int>& houses, int k) {

        int n = houses.size();
        sort(houses.begin(), houses.end()); // 거리순 정렬

        // 어떤 구간(l ~ r)에 사서함이 하나 생기면 드는 비용
        // 구간 비용을 미리 계산
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int r = 0; r < n; ++r) {
            for (int l = 0; l <= r; ++l) {
                
                int median = houses[(l + r) / 2];
                
                for (int i = l; i <= r; ++i) {
                    cost[l][r] += abs(houses[i] - median);
                }
            }
        }

        // DP 배열 초기화
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[0][0] = 0;

        // DP 배열 채우기
        for (int i = 1; i <= n; ++i) { // i index 까지 고려
            for (int g = 1; g <= k; ++g) { // 사서함 k 개 설치

                for (int m = 0; m < i; ++m) { // 0 <= m < i

                    if (dp[m][g - 1] != INT_MAX) {

                        dp[i][g] = min(
                            dp[i][g],
                            dp[m][g - 1] + cost[m][i - 1]
                        );
                        // dp[i][g] : 사서함이 하나 더 설치 되어도 비용이 변하지 않음
                        // dp[m][g - 1] + cost[m][i - 1] : 사서함이 하나 추가되면 비용이 변함
                        //          기존에 존재하던 사서함과 그대로 계산하는 그룹과 새로 추가된 사서함과 계산하는 두개의 그룹으로 찢어짐.
                        //          두개의 분할 기점을 m 으로 잡는다. (0 ~ m), (m ~ i)
                    }
                }
            }
        }

        return dp[n][k];
    }
};