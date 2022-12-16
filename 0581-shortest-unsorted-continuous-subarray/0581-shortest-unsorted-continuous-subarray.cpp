class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> sortArr(nums.begin(), nums.end());
        
        sort(sortArr.begin(), sortArr.end());
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < nums.size() && sortArr[l] == nums[l])
            l++;
        
        while(r >= 0 && sortArr[r] == nums[r])
            r--;
        
        return l < r ? r - l + 1 : 0;
    }
};