class Solution {
public:
/*
    // target 과 동일한 사이즈이고 각 원소가 0인 상태에서
    // 연속 부분배열을 선택해서 1씩 증가 시킬때..
    // target 과 동일한 배열이 되기 위해 최소 몇회의 증가 작업을 해야하는지..

    // dp[l][r]
    //      상태 : (l ~ r) 구간에 증가작업을 모두 처리함
    //      값 : 증가 작업 횟수 (최소)

    // dp[l][r] = max(
    //              dp[l][r],
    //              dp[l][i - 1] + dp[i + 1][r] + 1
    //            )
    // "dp[l][i - 1] + dp[i + 1][r] + 1" 이게 아니고
    // "dp[l][i] + dp[i + 1][r] + (l~r) 구간의 최솟값" 이다.
    //              i index 를 중간에 뺄 필요가 없음
    //              두 구간으로 나누고 두 구간의 최솟값을 더한 값에 중복 연산 수를 뺀다.
    int minNumberOperations(vector<int>& target) {
        
        int n = target.size();

        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(n, INT_MAX)); 
        // 양 끝점 여유분 필요 없음

        for (int len = 1; len <= n; len++) {
            
            
            for (int l = 0; l <= n - len; l++) { // l, r 은 (0 ~ n-1)
                int r = l + len - 1;
                
                if (len == 1) {
                    dp[l][r] = target[l]; // l == r 이면 증가 작업 횟수가 그 값 자체
                } else {
                    
                    int LRMin = *min_element(target.begin() + l, target.begin() + r + 1); // l~r 구간 최소 값

                    for (int i = l; i < r; i++) {
                        
                        dp[l][r] = min(
                            dp[l][r],
                            dp[l][i] + dp[i + 1][r] - LRMin
                        );
                        // dp[l][r] : i를 변경하면서 갱신
                        // dp[l][i] + dp[i + 1][r] - LRMin
                        //          두 구간으로 나누고 두 구간의 최소값을 더하면 LRMin 만큼 중복 연산이 생겨서 빼줌
                    }
                }
            }
        }

        return static_cast<int>(dp[0][n - 1]);
    }
*/

    // 위 방법은 dp 를 이용하여 푸는 방법 O(n^3) 이나 시간제한에 걸린다.
    // 아래방법이.. O(n) 으로 풀 수 있다..
    int minNumberOperations(vector<int>& target) {
        int operations = target[0]; // 첫 번째 원소만큼 초기 작업 횟수 설정
        
        for (int i = 1; i < target.size(); ++i) {
            if (target[i] > target[i - 1]) {
                operations += target[i] - target[i - 1]; // 이전 원소보다 클 때 차이만큼 작업 횟수 추가
            }
        }
        
        return operations;
    }
};