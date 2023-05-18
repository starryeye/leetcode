class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> um;
        
        for(auto m : magazine) {
            um[m]++;
        }
        
        for(auto r : ransomNote) {
            
            if(um.find(r) == um.end() || um[r] == 0)
                return false;
            
            um[r]--;
        }
        
        return true;
    }
};