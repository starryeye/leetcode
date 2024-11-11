class Solution {
private:
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    int dfs(int y, int x, vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        if (dp[y][x] != -1)
            return dp[y][x];

        int maxLength = 1; // (y, x) 위치에서의 초기 길이

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= matrix.size() || nx >= matrix[0].size()) {
                continue;
            }

            if (matrix[ny][nx] <= matrix[y][x]) {
                continue;
            }

            maxLength = max(maxLength, 1 + dfs(ny, nx, matrix, dp));
        }

        dp[y][x] = maxLength; // dp 배열에 최대 길이 저장 (메모이제이션)
        return dp[y][x];
    }

public:
    // dp[y][x]
    //      상태 : (y, x) 좌표에 존재한다.
    //      값 : (y, x) 에서 출발해서 가장 긴 증가 경로의 길이
    // dp 를 dfs check 겸용으로 사용가능
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); // dp 배열을 -1로 초기화

        int maxPath = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxPath = max(maxPath, dfs(i, j, matrix, dp)); // 각 셀에서 가장 긴 증가 경로 계산
            }
        }

        return maxPath;
    }
};