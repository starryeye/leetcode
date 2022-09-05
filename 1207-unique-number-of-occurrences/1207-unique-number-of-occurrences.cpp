class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> um;
        unordered_set<int> us;
        
        for(auto a : arr) {
            um[a]++;
        }
        
        for(auto u : um) {
            if(us.find(u.second) == us.end())
                us.insert(u.second);
            else
                return false;
        }
        
        return true;
    }
};