class Solution {
public:
    //prefix, suffix product
    //time O(N), space O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        int r = 1;
        int l = 1;
        
        //that is a result vector that we will have to return. Apart from that there is no other space that is being used in this solution
        vector<int> answer(n, 1);
        
        for(int i = 0; i<n; i++) {
            answer[i] *= l;
            
            l *= nums[i];
            
            answer[n-1 - i] *= r;
            
            r *= nums[n-1 - i];
            
        }
        
        return answer;
    }
};