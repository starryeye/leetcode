class Solution {
public:
    int rob(vector<int>& nums) {
        //주어진 배열이 곧 dp 배열인듯.
        
        int n = nums.size();
        
        //예외 처리
        if(!n)
            return 0;
        else if(n == 1)
            return nums[0];
        
        for(int i = 1; i < n; i++)
        {
            int tmpMax = nums[i];
            for(int j = 0; j < i; j++)
            {
                if(i - j > 1) // 핵심 코드 : 직전 집이 바로 옆집이면 안된다. 
                {
                    tmpMax = max(tmpMax, nums[i]+nums[j]);
                }
            }
            nums[i] = tmpMax;
        }
        
        return max(nums[n-1], nums[n-2]); //최댓값은 항상 맨마지막 또는 그 바로앞이다.
    }
};