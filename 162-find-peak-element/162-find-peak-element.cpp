class Solution {
public:
    //binary search는 정렬이 되어있는 경우에 특정 값을 찾을 때 사용하는 O(logN) 탐색 알고리즘이다..
    //이문제에 어떻게.. 적용할 생각을 했지....
    //뇌를 열어놓고 생각해야함.. 피크 지점을 찾는 "이분" 탐색법
    int findPeakElement(vector<int>& nums) {
        
        int low = 0, high = nums.size() - 1;
        
        while (low < high - 1) {
            
            int mid = (low + high) / 2;
            
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) 
                return mid;
            else if (nums[mid] > nums[mid + 1]) // mid-1 > mid > mid + 1 인경우 이다.. mid 인덱스보다 작은 인덱스에 peak가 있을 거라 생각
                high = mid - 1;
            else                                // mid-1 < mid < mid + 1 인경우 이다.. mid 인덱스보다 큰 인덱스에 peak가 있을 거라 생각
                low = mid + 1;    
        }
        return nums[low] > nums[high] ? low : high;
    }
    
    
};