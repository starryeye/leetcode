class Solution {
public:
    //(low + high) could be very big number which could exceed the integer range. As on left side, i.e. --> int mid.
    //mid is integer type. So, right side should also be of integer type.
    //(high-low) is an integer type, which will not get overflow problem
    
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2; //To avoid integer type overflow 
            
            if(nums[mid] == target) {
                return mid;
            }else if(nums[mid] < target) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
};