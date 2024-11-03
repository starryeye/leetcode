class Solution {
public:
    // dp[i]
    //      상태 : i index 를 마지막 요소로 포함하는 부분 배열
    //      값 : 요소 개수(길이) 최대값
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int cur = 1; cur < n; cur++) {

            int candidate = 0;
            for (int prev = 0; prev < cur; prev++) {

                if (nums[prev] < nums[cur]) {
                    candidate = max(dp[prev] + 1, candidate);
                }
            }
            
            dp[cur] = max(candidate, 1);
        }

        return *max_element(dp.begin(), dp.end());
    }

/*
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        vector<int> dp(n, 1);
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j]+1);//dp 저장
                    ans = max(ans, dp[i]);//답
                }
            }
        }
        
        if(ans == 0)
            return 1; //모든 원소가 값이 동일 할때는 ans 가 0되어 예외처리
        return ans;
    }
*/
};