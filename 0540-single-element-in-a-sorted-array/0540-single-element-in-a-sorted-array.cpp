class Solution {
public:
    // 0 ~ index + 1 까지 정상의 경우..
    // -> index가 짝수면 무조건 index + 1과 값동일
    // -> index가 홀수면 무조건 index - 1과 값동일
    int singleNonDuplicate(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < r) {
            
            int mid = l + (r - l)/2;
            
            if((mid % 2 == 0) && (nums[mid] == nums[mid + 1])) // 짝수
                l = mid + 2;
            else if((mid % 2 == 1) && (nums[mid] == nums[mid - 1])) // 홀수
                l = mid + 1;
            else
                r = mid;
        }
        
        return nums[r]; //l or r 모두 가능
    }
};