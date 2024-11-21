class Solution {

private:
    // 이진 탐색 함수: 현재 이벤트와 겹치지 않는 마지막 이벤트 찾기
    int findPreviousEvent(const vector<vector<int>>& events, int current) {

        int low = 0, high = current - 1;
        
        while (low <= high) {

            int mid = (low + high) / 2;
            
            if (events[mid][1] < events[current][0]) { // 이전 이벤트의 종료일 < 현재 이벤트의 시작일
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high; // 겹치지 않는 마지막 이벤트의 인덱스 반환
    }


public:
    // events[i] = [startDay i, endDay i, value i]
    // k : 참석 가능한 최대 이벤트 수

    // 최대 가치는?

    // dp[i][j]
    //      상태 : 처음 i개의 이벤트 중 최대 j개의 이벤트를 선택
    //      값 : 최대 가치
    int maxValue(vector<vector<int>>& events, int k) {

        int n = events.size();
    
        // 종료일 기준으로 정렬
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // DP 테이블 초기화
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // DP 진행
        for (int i = 1; i <= n; ++i) {
            
            int prev = findPreviousEvent(events, i - 1); // 현재 이벤트와 겹치지 않는 마지막 이벤트 찾기
            
            for (int j = 1; j <= k; ++j) {
                // 이벤트를 선택하지 않는 경우
                dp[i][j] = dp[i - 1][j];
                // 이벤트를 선택하는 경우
                dp[i][j] = max(dp[i][j], dp[prev + 1][j - 1] + events[i - 1][2]);
            }
        }

        return dp[n][k];
    }
};