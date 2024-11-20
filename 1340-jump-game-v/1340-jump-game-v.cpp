class Solution {
public:

    // 주어진 arr 배열의 각 인덱스를 "점프"하여 이동할 수 있다.
    // 점프
    //      왼쪽 또는 오른쪽으로 주어진 최대 d 거리만큼 이동할 수 있다.
    //      현재 위치의 값보다 더 큰 값을 가진 인덱스로는 이동할 수 없다.

    // 가능한 모든 경로에서 가장 긴 점프 시퀀스를 찾아 그 길이를 반환

    // dp[i]
    //      상태 : 인덱스 i에서 시작
    //      값 : 최대 이동 가능한 위치의 수
    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();
        vector<int> dp(n, 1); // dp[i]는 최소 자기 자신만 방문 가능 (최소값은 1)
    
        // 높이를 기준으로 인덱스를 정렬 (높이 오름차순)
        vector<pair<int, int>> heights;
        for (int i = 0; i < n; ++i) {
            heights.push_back({arr[i], i}); // k: arr값, v: arr인덱스
        }
        sort(heights.begin(), heights.end());

        // DP 배열 계산
        for (const auto& [height, index] : heights) { // 높이 오름차순 순회
            
            // 왼쪽으로 점프
            for (int left = index - 1; left >= max(0, index - d); --left) {

                if (arr[left] >= arr[index]) 
                    break; // 높이가 같거나 높은 곳에서 멈춤
                dp[index] = max(dp[index], dp[left] + 1); // 최대 점프 거리 갱신
            }

            // 오른쪽으로 점프
            for (int right = index + 1; right <= min(n - 1, index + d); ++right) {

                if (arr[right] >= arr[index]) 
                    break; // 높이가 같거나 높은 곳에서 멈춤
                dp[index] = max(dp[index], dp[right] + 1); // 최대 점프 거리 갱신
            }
        }

        // dp 배열에서 최댓값 반환
        return *max_element(dp.begin(), dp.end());
    }
};