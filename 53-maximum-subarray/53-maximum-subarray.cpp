class Solution {
public:
    //https://leetcode.com/problems/maximum-subarray/discuss/1595195/C++Python-7-Simple-Solutions-w-Explanation-or-Brute-Force-+-DP-+-Kadane-+-Divide-and-Conquer
    //참고하면 좋음
    /*
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        
        // dp[i] : 0 ~ i 인덱스의 sub array 중 i 인덱스를 포함하는 sub array들의 max sum
        vector<int> dp(nums.begin(), nums.end());
        
        for(int i=1; i<nums.size(); i++) {
            
            // dp[i]가 max라는 말은 nums[i]가 max 값 즉, 그 전의 sub array(dp[i-1])는 음수이므로 버리겠다는 뜻이다.
            dp[i] = max(dp[i], dp[i-1] + nums[i]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    */
    //prefix sum 아님?
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        
        int prefix = 0;
        
        int answer = nums[0];
        int minNum = 0; //주의! 공집합은 합이 0이다, minNum이 0이라는 말은.. prefix 자체가 max라는 말!
        
        for(int i=0; i<nums.size(); i++) {
            
            //prefix
            prefix += nums[i];
            
            answer = max(answer, prefix - minNum);
            minNum = min(prefix, minNum);
        }
        
        return answer;
    }
    
};