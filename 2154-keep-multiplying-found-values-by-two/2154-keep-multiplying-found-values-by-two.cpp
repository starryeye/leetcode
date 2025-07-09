class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        unordered_set<int> us;
        for (int& n : nums) {
            us.insert(n);
        }

        while(us.find(original) != us.end()) {
            original = original * 2;
        }

        return original;
    }
};