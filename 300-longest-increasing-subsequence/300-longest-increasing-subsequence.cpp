class Solution {
public:
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
};