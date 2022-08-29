class Solution {
public:
    
    string toNumberPattern(string w) {
        
        unordered_map<char, char> us; //하나의 단어 내에서 겹치는 문자가 있는가..
        string s;
        char count = 'a';
            
        for(int i = 0; i < w.size(); i++) {
            
            if(us.find(w[i]) == us.end()) {
            
                us[w[i]] = count;
                s += count;
                count++;
                
            }else {
                s += us[w[i]];
            }
        }
        
        return s;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        unordered_map<string, vector<string>> um;
        
        //words를 숫자 패턴으로 변경 (ex. abb -> 122, gee -> 122)
        for(auto w : words) {
            
            um[toNumberPattern(w)].push_back(w);
        }
        
        //pattern을 숫자 패턴으로 변경
        return um[toNumberPattern(pattern)];
    }
};