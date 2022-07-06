class Solution {
public:
    
    //binary search 응용
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while (l <= r) {
            
            int mid = (l+r) / 2;
            
            if (target == nums[mid])
                return mid;
            
            //if 와 else if는 로테이션일 경우이다.
            if (nums[mid] > nums[r]) {
                //로테이션 있음.. 
                if (target < nums[mid] && target >= nums[l]) //nums[l] <= target < nums[mid] 인경우
                    r = mid - 1;
                else
                    l = mid + 1;
            }else if (nums[mid] < nums[l]) {
                //로테이션 있음.. 
                if (target > nums[mid] && target <= nums[r]) //nums[mid] < target <= nums[r] 인경우
                    l = mid + 1;
                else
                    r = mid - 1;
            }else {
                //로테이션 없음.. 노멀 바이너리 서치
                if (target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};