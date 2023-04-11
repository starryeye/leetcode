// 내풀이가 왜틀렸는지.. 이해 안되고 discuss도 이해가 되지 않는다..
// class Solution {
// public:
//     int numTilings(int n) {
        
//         vector<int> dp(4, 0); // dp[0] 은 생략
        
//         dp[1] = 1;
//         dp[2] = 2;
//         dp[3] = 5; // 예제
        
//         if(n <= 3)
//             return dp[n];
        
//         //마지막 상황에서 보면.. [n-3] 에서 * 2(ㄱ으로 채우기) + [n-2] 에서 * 1(-로 채우기) + [n-1] 에서 * 1(1로 채우기)
//         for(int i = 4; i <= n; i++) {
//             dp.push_back(dp[n-3] * 2 + dp[n-2] * 1 + dp[n-1] * 1);
//         }
        
//         return dp[n];
//     }
// };

class Solution {
public:
    int numTilings(int n) {
        if (n < 3) return n;
        
        int mod = pow(10, 9) + 7;
        vector<long> D(n+1, 0), T(n+1, 0);
        D[0] = 0, D[1] = 1, D[2] = 2;
        T[0] = 0, T[1] = 1, T[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            D[i] = (D[i-1] + D[i-2] + 2*T[i-2]) % mod;
            T[i] = (T[i-1] + D[i-1]) % mod;
        }
        
        return D[n];
    }
};