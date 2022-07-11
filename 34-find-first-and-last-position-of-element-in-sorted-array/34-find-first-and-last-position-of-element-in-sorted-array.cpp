class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size() - 1;
        
        int hand = 0;
        bool isFind = false;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] == target) {
                hand = mid;
                isFind = true;
                break;
            }else if(nums[mid] < target) {
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        if(isFind == false)
            return {-1, -1};
        
        int l2 = hand - 1;
        int r2 = hand + 1;
        
        while(0 <= l2) {
            if(target != nums[l2]) {
                break;
            }else{
                l2--;
            }
        }
        l2++;
        
        while(r2 < nums.size()) {
            if(target != nums[r2]) {
                break;
            }else {
                r2++;
            }
        }
        r2--;
        
        return {l2, r2};
        
        
    }
};