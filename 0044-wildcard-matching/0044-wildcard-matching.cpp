class Solution {
public:
    // ? : 임의의 문자 하나외 매칭됨
    // * : 0 개 이상의 문자열과 매칭됨

    // 주어진 s 문자열이 주어진 패턴 문자열 p 에 매칭이 되는지 리턴

    // 정답
    // dp[i][j]
    //      상태 : s의 i 개의 문자와 p의 j 개의 문자
    //      값 : 매칭되는지 여부
    //              dp[i][j] = true라면 s[0:i]와 p[0:j]가 매칭

    // 패턴의 p[j-1]가 문자 s[i-1]와 같거나 ?인 경우
    //          이전 상태 dp[i-1][j-1]의 값과 동일
    // 패턴이 *인 경우
    //          dp[i][j] = dp[i][j-1] || dp[i-1][j]
    //              *가 빈 문자열로 취급되면 dp[i][j-1]와 같고, 
    //              하나 이상의 문자로 취급되면 dp[i-1][j]와 같다.

    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();
        
        // DP 테이블 초기화
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // 초기 조건
        dp[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1]; // dp[0][j] 패턴 p의 첫 j 개 문자가 모두 *일 때 true
            }
        }

        // DP 테이블 채우기
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {

                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};