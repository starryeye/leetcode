class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<char, int> um;
        
        for(int i = 0; i < order.size(); i++) {
            um[order[i]] = i;
        }
        
        sort(s.begin(), s.end(),
            [&](char a, char b) {return um[a] < um[b]; });
        
        return s;
    }
};