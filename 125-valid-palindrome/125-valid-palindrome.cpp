class Solution {
public:
    bool isPalindrome(string s) {
        
        string temp;
        
        // 필터링
        for(int i =0; i<s.size(); i++) {
            if(65 <= s[i] && s[i] <= 90 || 48 <= s[i] && s[i] <= 57) {
                temp += s[i];
            } else if(97 <= s[i] && s[i] <= 122) {
                temp += s[i] - 32;
            }
        }
        
        // two pointer!!
        for(int i=0; i < temp.size() / 2; i++) {
            if(temp[i] != temp[temp.size()-1 -i])
                return false;
        }
        
        return true;
    }
};