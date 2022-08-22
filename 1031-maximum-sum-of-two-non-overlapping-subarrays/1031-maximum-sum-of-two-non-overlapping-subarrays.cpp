class Solution {
public:
    int window(vector<int>& A, int L, int R) {
    
        int n = A.size();

        int preSum = 0;
        int sufSum = 0;
        int ret = 0;

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        for(int i = 0; i < n; i++) {
            if(i < L) {

                preSum += A[i];
                dp1[i] = preSum;
            }else {

                preSum = preSum + A[i] - A[i - L];
                dp1[i] = max(dp1[i - 1], preSum);
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            if(i + R > n - 1) {

                sufSum += A[i];
                dp2[i] = sufSum;
            } else {

                sufSum = sufSum + A[i] - A[i + R];
                dp2[i] = max(dp2[i + 1], sufSum);
            }
        }

        for(int i = L - 1; i < n - R; i++) {
            ret = max(ret, dp1[i] + dp2[i + 1]);
        }

        return ret;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        if(firstLen + secondLen > static_cast<int>(nums.size()))
            return -1;

        return max(window(nums, firstLen, secondLen), window(nums, secondLen, firstLen));
    }
};