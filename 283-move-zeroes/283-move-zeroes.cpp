class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
       for(auto itr = remove(nums.begin(), nums.end(), 0); itr != nums.end(); itr++) {
           *itr = 0;
       }
    }
};