class Solution {
public:
    // 돌 갯수를 나타내는 stones 배열
    // 병합
    //      주어진 k 개의 연속 돌 무더기(배열의 원소) 를 선택해서 병합을 한다. 
    //      병합의 비용은 돌의 갯수 총합이다.
    // 돌 무더기가 1개가 될때까지 병합할때 최소 비용

    // dp[l][r]
    //      상태 : (l ~ r) 구간을 병합함
    //      값 : 병합에 든 비용 (최소)
    //      최종 : dp[0][n-1]
    int mergeStones(vector<int>& stones, int K) {

        int n = stones.size();
        
        if ((n - 1) % (K - 1) != 0) return -1; 
        // n-1 이 k-1 의 배수여야 최종 하나로 합쳐진다. (나머지가 0이면 가능하다는 뜻)
        //      k 개를 하나로 합치면 k-1 개가 매번 줄어든다... 에서 논리를 확장하면 나오는듯..

        vector<int> prefix(n + 1);
        for (int i = 0; i <  n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        vector<vector<int> > dp(n, vector<int>(n));

        for (int m = K; m <= n; ++m) { // 몇개의 돌무더기(원소)를 병합할 것인가.. len..

            for (int l = 0; l + m <= n; ++l) {
                int r = l + m - 1;

                dp[l][r] = INT_MAX;
                
                // 구간 [l, r]을 K개의 더미씩 나눠 병합해봄
                for (int mid = l; mid < r; mid += K - 1) { // K배수로 loop.. 인데.. K 개를 1개로 합치면 K-1 개씩 줄어든다.
                    dp[l][r] = min(
                        dp[l][r],
                        dp[l][mid] + dp[mid + 1][r]
                    );
                }
                    
                if ((r - l) % (K - 1) == 0) { // K개로 병합이 불가능하다.
                    dp[l][r] += prefix[r + 1] - prefix[l];
                }
            }
        }

        return dp[0][n - 1];
    }
};