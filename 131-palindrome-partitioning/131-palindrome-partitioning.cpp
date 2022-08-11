class Solution {
public:
    
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    void dfs(int index, string s, vector<string>& tmp, vector<vector<string>>& answer) {
        if(index == s.size()) {
            answer.push_back(tmp);
        }
        
        for(int i = index; i < s.size(); i++) {
            
            
            if(isPalindrome(s, index, i)) {
                
                tmp.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, tmp, answer);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> answer;
        
        vector<string> tmp;
        
        dfs(0, s, tmp, answer);
        
        return answer;
    }
};