class Solution {
public:
    int rob(vector<int>& nums) {
        //주어진 배열이 곧 dp 배열인듯.
        
        int n = nums.size();
        
        if(!n)
            return 0;
        else if(n == 1)
            return nums[0];
        
        for(int i = 1; i < n; i++)
        {
            int tmpMax = nums[i];
            for(int j = 0; j < i; j++)
            {
                if(i - j > 1)
                {
                    tmpMax = max(tmpMax, nums[i]+nums[j]);
                }
            }
            nums[i] = tmpMax;
        }
        
        return max(nums[n-1], nums[n-2]);
    }
};