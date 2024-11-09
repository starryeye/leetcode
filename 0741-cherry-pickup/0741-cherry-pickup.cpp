class Solution {
public:
    // (0, 0) -> (n, m) 으로 이동하면서 1차 채집
    // (n, m) -> (0, 0) 으로 이동하면서 2차 채집
    // 으로 할줄 알았으나..
    // 두 번의 이동을 각각 계산하기 어렵기 때문에, 두 사람이 동시에 이동하면서 체리를 수집하는 방식으로 문제를 해결
    // -> 두 사람은 (0, 0) 에서 동시에 출발하고, 동일한 좌표에 갈 경우엔 체리를 한번만 수집하는 것으로 한다.
    // 그러면, 두사람의 이동 횟수와 이동 방향은 동일하므로 y1 + x1 = y2 + x2 는 항상 참이다.
    // 따라서 dp[y1][x1][y2] 만 사용해도 x2 는 특정 되므로 3차원 dp 를 사용하면 됨.

    // dp[y1][x1][y2]
    //      상태 : 두 사람이 각각 (0, 0) 에서 출발하여 (y1, x1), (y2, y1+x1-y2) 좌표에 존재
    //      값 : 체리 획득 갯수 (최대)
    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        
        // DP 배열 초기화
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][0] = 0;  // 시작점에서의 체리 수가 0이 아닐 수 있지만, 아래 점화식이 (0, 0) 부터 작동되는 식이라 0으로 초기화
        
        for (int y1 = 0; y1 < n; ++y1) {
            for (int x1 = 0; x1 < n; ++x1) {
                for (int y2 = 0; y2 < n; ++y2) {

                    int x2 = y1 + x1 - y2;  // 두 번째 사람 x값
                    
                    // 경계를 벗어나거나 장애물을 만나는 경우
                    if (x2 < 0 || x2 >= n || grid[y1][x1] == -1 || grid[y2][x2] == -1) {
                        continue;
                    }
                    
                    // (0, 0) 출발하여, 현재 위치까지 오기 위해 가능한 이전 위치에서 최대 체리 수 찾기
                    int cherries = dp[y1][x1][y2];
                    if (y1 > 0 && y2 > 0) 
                        cherries = max(cherries, dp[y1 - 1][x1][y2 - 1]); // 아래, 아래
                    if (y1 > 0 && x2 > 0) 
                        cherries = max(cherries, dp[y1 - 1][x1][y2]); // 아래, 오른
                    if (x1 > 0 && y2 > 0) 
                        cherries = max(cherries, dp[y1][x1 - 1][y2 - 1]); // 오른, 아래
                    if (x1 > 0 && x2 > 0) 
                        cherries = max(cherries, dp[y1][x1 - 1][y2]); // 오른, 오른
                    
                    // 이동이 불가능
                    if (cherries < 0) continue;
                    
                    // 현재 위치의 체리 수를 추가 (같은 위치는 중복 수집 방지)
                    cherries += grid[y1][x1];
                    if (y1 != y2) cherries += grid[y2][x2];
                    
                    // dp 테이블 갱신
                    dp[y1][x1][y2] = cherries;
                }
            }
        }
        
        // 결과 반환: 끝 지점에 도달한 최대 체리 수, 갈 수 없다면 0
        return max(0, dp[n - 1][n - 1][n - 1]);
    }
};