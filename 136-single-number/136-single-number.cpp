class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int, int> um;
        
        for(auto num : nums) {
            
            if(!um[num])
                um[num]++;
            else
                um.erase(num);            
        }
        
        for(auto um : um) {
            return um.first;
        }
        
        return -1;
        
    }
};