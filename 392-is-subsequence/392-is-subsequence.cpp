class Solution {
public:
    
    int solv(char a, int start, string t) {
        
        for(int i = start; i < t.size(); i++) {
            if(t[i] == a)
                return i+1;//다음부터는 그다음 index부터 봐야함
        }
        
        return -1;
    }
    
    bool isSubsequence(string s, string t) {
        
        int hand = 0;
        for(int i = 0; i < s.size(); i++) {
            hand = solv(s[i], hand, t);
            
            if(hand == -1)
                return false;
        }
        
        return true;
    }
};