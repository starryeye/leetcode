//2회차
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int cursor = 0;
        
        for(int i = 0; i < t.size(); i++) {
            if(s[cursor] == t[i])
                cursor++;
        }
        
        return cursor == s.size();
    }
};