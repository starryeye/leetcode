class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //답이 곧 dp 배열
        
        vector<unsigned int> dp(target+1, 0);
        
        dp[0] = 0;
        
        //nums 배열의 값의 dp 는 1로 시작해야한다.
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > target)
                continue;
            
            dp[nums[i]] = 1;
        }
        
        for(int i=1; i<=target; i++)
        {
            for(int j=0; j<i; j++) //밑에 정답지를 보니.. j for문을 없앨수도 있다..
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



/*
//정답
int combinationSum4(vector<int>& nums, int target)
{
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1; //dp[0]에 1을 해놓으면 내가 해놓은 1 초기화 없어도됨..
    
    for (int i = 1; i <= target; ++i)
    {
        for (int x = 0; x < nums.size(); ++x)
        {
            if (i >= nums[x])
                dp[i] += dp[i - nums[x]];
        }
    }
    
    return dp[target];
}
*/