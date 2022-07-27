class Solution {
public:
    
    void recur(vector<string>& v, int l, int r, string str) {
        
        if(l == 0 && r == 0) {
            v.push_back(str);
        }
        
        if(l > 0) {
            
            recur(v, l-1, r+1, str + "(");
        }
        
        if(r > 0) {
            
            recur(v, l, r-1, str + ")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> v;
        
        string str;
        
        recur(v, n, 0, str);
        
        return v;
    }
};