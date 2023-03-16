class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        while(nums.size() != 1) {
            
            int prevNum = nums[0];
            
            for(int i = 1; i < nums.size(); i++) {
                nums[i - 1] = (prevNum + nums[i]) % 10;
                prevNum = nums[i];
            }
            
            nums.erase(nums.begin() + nums.size() - 1);
        }
        
        return nums[0];
    }
};