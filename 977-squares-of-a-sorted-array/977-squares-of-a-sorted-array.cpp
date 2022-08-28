class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> answer(nums.size());
        
        int insert = nums.size() -1;
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r) {
            
            if(abs(nums[l]) < abs(nums[r])) {
                
                answer[insert] = pow(nums[r], 2);
                insert--;
                r--;
            }else {
                
                answer[insert] = pow(nums[l], 2);
                insert--;
                l++;
            }
        }
        
        return answer;
    }
};