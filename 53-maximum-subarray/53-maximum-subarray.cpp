class Solution {
public:
    //https://leetcode.com/problems/maximum-subarray/discuss/1595195/C++Python-7-Simple-Solutions-w-Explanation-or-Brute-Force-+-DP-+-Kadane-+-Divide-and-Conquer
    //참고하면 좋음
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        
        // dp[i] : 0 ~ i 인덱스의 sub array 중 i 인덱스를 포함하는 sub array들의 max sum
        vector<int> dp(nums.begin(), nums.end());
        
        for(int i=1; i<nums.size(); i++) {
            
            // dp[i]가 max라는 말은 0이 max 값 즉, 그 전의 sub array는 음수이므로 버리겠다는 뜻이다.
            dp[i] = max(dp[i], dp[i-1] + nums[i]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};