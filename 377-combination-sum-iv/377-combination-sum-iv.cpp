class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //답이 곧 dp 배열
        
        vector<unsigned int> dp(target+1, 0);
        
        dp[0] = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > target)
                continue;
            
            dp[nums[i]] = 1;
        }
        
        for(int i=1; i<=target; i++)
        {
            for(int j=0; j<i; j++)
            {
                for(int x=0; x<nums.size(); x++)
                {
                    if(i == j + nums[x])
                    {
                        dp[i] += dp[j];
                    }
                }
            }
        }
        
        return dp[target];
    }
};
