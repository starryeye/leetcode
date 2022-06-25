class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> us;
        
        for(int i = 0; i < nums.size(); i++) {
            if(us.find(nums[i]) == us.end())
                us.insert(nums[i]);
            else
                return true;
        }
        
        return false;
        
    }
    /*
    //genius
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();        
    }
    */
};