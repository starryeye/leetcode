class Solution {
public:
    // 돌의 위치가 담긴 배열이 주어짐.
    // 개구리는 첫번째 돌에서 시작함
    // 개구리는 첫번째 점프는 1칸 점프 가능
    //      두번째 부터는 이전 점프 k칸의 k+1, k-1, k칸으로 점프 가능 
    // 마지막 돌에 도달할 수 있으면 true 반환 아니면 false 반환

    // dp[i][k]
    //      상태: 개구리가 점프로 k칸 움직여서 i index 돌에 위치
    //      값 : 가능 여부
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();

        // 돌의 위치에 대해 인덱스를 값으로 할당한다.
        unordered_map<int, int> mark;
        for (int i = 0 ; i < n; i++) {
            mark[stones[i]] = i;
        }
        
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        dp[0][0] = true; // 최초 상태는 가능하다.

        for (int i = 0; i < n; i++) { // 모든 돌 순회
            for (int prevJump = 0; prevJump <= n; prevJump++) { // 가능한 점프

                if (dp[i][prevJump]) { // 현재 상태가 가능한 상태인지 확인

                    int nextJump1 = prevJump;
                    int nextJump2 = prevJump + 1;
                    int nextJump3 = prevJump - 1;

                    // 다음 상태 업데이트
                    if (mark[stones[i] + nextJump1]) { // 돌 존재 여부
                        dp[mark[stones[i] + nextJump1]][nextJump1] = true;
                    }
                    if (mark[stones[i] + nextJump2]) { // 돌 존재 여부
                        dp[mark[stones[i] + nextJump2]][nextJump2] = true;
                    }
                    if (mark[stones[i] + nextJump3]) { // 돌 존재 여부
                        dp[mark[stones[i] + nextJump3]][nextJump3] = true;
                    }
                }
            }
        }
        
        // If any value with index as n - 1 is true, return true.
        for (int prevJump = 0; prevJump <= n; prevJump++) {
            if (dp[n - 1][prevJump]) {
                return true;
            }
        }
        return false;
    }
};