class Solution {
private:
    const int MOD = 1e9 + 7;

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    int dfs(int cy, int cx, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        
        if (dp[cy][cx] != -1) 
            return dp[cy][cx];

        dp[cy][cx] = 1; // 자기 자신 경로

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || nx < 0 || ny >= dp.size() || nx >= dp[0].size())
                continue;

            if (grid[cy][cx] < grid[ny][nx]) { // strictly increasing 조건

                dp[cy][cx] = (dp[cy][cx] + dfs(ny, nx, dp, grid)) % MOD;
            }
        }

        return dp[cy][cx];
        // 더이상 진행 불가하면 1로 리턴됨
    }

public:
    // dp[y][x]
    //      상태: (y, x) 좌표에서 출발해서 strictly increasing 경로를 만든다.
    //      값: 경로 경우의 수
    int countPaths(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        // -1 이면 아직 계산 되지 않았다는 뜻. (check 역할도 함)

        int answer = 0;

        // 모든 출발지 순회
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                
                answer = (answer + dfs(i, j, dp, grid)) % MOD;
            }
        }

        return answer;
    }
};