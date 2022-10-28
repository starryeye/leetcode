class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        
        int i = 0;
        
        for(int j = 0; j < s.size(); j++) {
            
            if(s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        
        //나머지 정리
        reverse(s.begin() + i, s.end());
    }
};