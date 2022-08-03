class Solution {
public:
    /*
    //오답
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        int l = 0;
        int r = n-1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] < nums[r])
                r = mid - 1;
            else if(nums[mid] > nums[r])
                l = mid + 1;
            else
                return nums[r]; // l == r == mid
        }
        
        return nums[l];
    }
    */
    
    //직접 디버깅하면서 보는게 가장 좋다..
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        int l = 0;
        int r = n-1;
        
        while(l < r) { // =을 붙이면 무한루프..
            int mid = l + (r - l) / 2;
            

            if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        
        return nums[l];
    }
};