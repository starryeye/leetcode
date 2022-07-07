class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();
        
        std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
    }
};