class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> um;
        
        for(auto n : nums) {
            um[n]++;
        }
        
        sort(nums.begin(), nums.end(),
             [&] (int a, int b) {
                 return um[a] == um[b] ? a > b : um[a] < um[b];
             });
        
        return nums;
    }
};