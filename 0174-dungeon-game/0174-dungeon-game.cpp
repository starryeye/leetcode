class Solution {
public:

    // (0, 0) 에서 (n, m) 으로 이동
    // 체력이 0 이하로 떨어지면 사망
    // 음수 : 체력 잃음
    // 0 : 빈방
    // 양수 : 체력 증가
    // 오른쪽 or 아래로만 이동
    // 이동가능한 최소의 초기 체력 구하기

    // 합으로 계산하면 안된다. (이동 도중에도 살아있어야함)
    
    // dp[i][j]
    //      상태 : (n, m) 에서 -> (i, j) 으로 이동(역방향) 했을 때..
    //      값 : 살아있을 수 있는 최소 체력
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int n = dungeon.size();
        int m = dungeon[0].size();

        // DP 배열 초기화: 마지막 칸까지 가기 위한 최소 체력을 저장
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // 도착점 초기화
        dp[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);

        // 마지막 행 초기화
        for (int i = n - 2; i >= 0; --i) {
            dp[i][m - 1] = max(1, dp[i + 1][m - 1] - dungeon[i][m - 1]);
        }

        // 마지막 열 초기화
        for (int j = m - 2; j >= 0; --j) {
            dp[n - 1][j] = max(1, dp[n - 1][j + 1] - dungeon[n - 1][j]);
        }

        // 나머지 DP 테이블 채우기
        for (int i = n - 2; i >= 0; --i) {
            for (int j = m - 2; j >= 0; --j) {

                int minHealthOnExit = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1, minHealthOnExit - dungeon[i][j]); // 0 이하이면 죽기 때문에 1을 항상 보장시켜줘야함
            }
        }

        // 시작점에서 필요한 최소 체력을 반환
        return dp[0][0];
    }
};