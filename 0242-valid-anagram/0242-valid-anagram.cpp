class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, int> um;
        
        for(int i = 0; i < s.size(); i++) {
            um[s[i]]++;
            um[t[i]]--;
        }
        
        for(auto u : um) {
            if(u.second > 0)
                return false;
        }
        
        return true;
    }
};