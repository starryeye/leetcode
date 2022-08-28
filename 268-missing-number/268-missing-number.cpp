class Solution {
public:
    //bit manipulation 해결법은 discuss로.. 한번 보기
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