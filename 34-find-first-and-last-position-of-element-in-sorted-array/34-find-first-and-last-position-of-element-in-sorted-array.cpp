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
    
    /*정답1
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target+1)-1;
        if (idx1 < nums.size() && nums[idx1] == target)
            return {idx1, idx2};
        else    
            return {-1, -1};
    }

    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = (r-l)/2+l;
            if (nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
    */
    /*정답2
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = std::lower_bound(nums.begin(), nums.end(), target);
        auto it2 = std::lower_bound(nums.begin(), nums.end(), target + 1);
        if (it1 != nums.end() && *it1 == target) 
            return {it1 - nums.begin(), it2 - nums.begin() - 1};
        return {-1, -1};
    }
    */
};