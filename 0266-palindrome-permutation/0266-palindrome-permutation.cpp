class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        unordered_map<char, int> um;
        
        int count = 0;
        
        for(auto c : s) {
            um[c]++;
        }
        
        for(auto u : um) {
            if(u.second % 2 == 1)
                count++;
        }
        
        return count <= 1;
    }
};