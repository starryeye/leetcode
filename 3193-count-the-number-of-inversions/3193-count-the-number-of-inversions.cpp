class Solution {
public:
    // requirements[i] : [끝인덱스, 역순 갯수] : 0 ~ 끝인덱스에 대해 역순이 몇개 존재해야한다.
    // 역순
    //      (i, j) 인덱스 쌍에 대해, i < j 이고 nums[i] > nums[j] 이다.
    // 값이 0부터 시작해서 n-1 까지 증가하는 n개의 원소를 가지는 배열에 대해
    // requirements 를 만족하는 배열의 갯수를 구하라..

    // dp[i][cnt]
    //      상태 : i index 까지 고려(i+1개 존재), 역순이 cnt 존재하는 상태
    //      값 : 만족하는 배열의 갯수(최대)

    // i 원소가 추가되면..
    // dp[i][cnt] = dp[i − 1][cnt − i] + dp[i − 1][cnt − (i − 1)] + ... + dp[i − 1][cnt]
    int numberOfPermutations(int n, vector<vector<int>>& requirements) { 

        vector<int> r(n + 1, -1); // requirements 저장
        
        for (auto &req: requirements) {
            r[req[0] + 1] = req[1];
        }

        int m = r[n];
        int mod = 1e9 + 7;
        
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0)); 
        
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int cnt = 0; cnt <= m; cnt++) {

                if (r[i] != -1 && cnt != r[i]) continue;
                
                for (int k = 0; k <= min(cnt, i - 1); k++) {
                    dp[i][cnt] = (dp[i][cnt] + dp[i - 1][cnt - k]) % mod;
                }
            }
        }

        return dp[n][r[n]];
    }
};