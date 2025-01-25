class Solution {
public:
    // string s 가 주어진다.
    // string s 의 substring(연속 원소) 들 중 palindromic substring 총 갯수를 구하여라

    // dp[left][right]
    //      상태 : left index 에서 right index 까지 고려
    //      값 : palindromic substrings 인지 여부
    int countSubstrings(string s) {
        
        int n = s.size();
        int answer = 0; // string s 의 palindromic substrings 갯수

        if (n <= 0) return 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // 초기화 - 원소 1개는 그자체로 palindromic substrings
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            answer++;
        }
        // 원소 2개 초기화
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                answer++;
            }
        }

        for (int length = 3; length <= n; length++) {

            for (int left = 0; left <= n - length; left++) {
                int right = left + length - 1;

                if (dp[left + 1][right - 1] == true && s[left] == s[right]) {
                    dp[left][right] = true;
                    answer++;
                }
            }
        }

        return answer;
    }
};