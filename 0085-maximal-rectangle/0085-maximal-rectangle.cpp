class Solution {
public:
    // dp[i][j][0]
    //      상태 : (i, j) 좌표를 오른쪽 아래 꼭짓점으로 하는 직사각형
    //      값 : 가로 최대 크기
    // dp[i][j][1]
    //      상태 : (i, j) 좌표를 오른쪽 아래 꼭짓점으로 하는 직사각형
    //      값 : 세로 최대 크기
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();    // 행 개수
        int m = matrix[0].size(); // 열 개수
        int maxArea = 0;

        // DP 배열 초기화
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, 0))); // 3차원 DP 배열

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    // 가로 크기 갱신
                    dp[i][j][0] = (j == 0 ? 1 : dp[i][j - 1][0] + 1);

                    // 세로 크기 갱신
                    dp[i][j][1] = (i == 0 ? 1 : dp[i - 1][j][1] + 1);

                    // 최대 면적 계산
                    int minWidth = dp[i][j][0];
                    for (int k = i; k >= 0; k--) { // 위로 탐색
                        minWidth = min(minWidth, dp[k][j][0]); // 최소 가로 길이 갱신
                        int area = minWidth * (i - k + 1);    // 직사각형 면적 계산
                        maxArea = max(maxArea, area);        // 최대 면적 갱신
                    }
                }
            }
        }

        return maxArea;
    }
};