class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        unordered_map<char, int> um;
        int tmp;
        
        for(int i = 0; i < s.size(); i++) {
            um[s[i]]++;
            tmp = um[s[i]];
        }
        

        for(auto u : um) {
            if(u.second != tmp)
                return false;
        }
        
        return true;
    }
};