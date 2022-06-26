class Solution {
public:
    
    //c++ nth_element, min-heap, partial_sort
    //https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        return nums[k-1];
    }
};