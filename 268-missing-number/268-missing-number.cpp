class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum = 0;
        int cmp = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            
            sum += nums[i];
            cmp += i+1;
        }
        
        return cmp - sum;
    }
};