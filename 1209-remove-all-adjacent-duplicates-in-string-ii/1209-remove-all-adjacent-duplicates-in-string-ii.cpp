class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        
        vector<pair<char, int>> st;
        string answer;
        
        for (auto ch : s) {
            
            if (st.empty() || st.back().first != ch) 
                st.push_back({ ch, 0 });
            
            if (++st.back().second == k) 
                st.pop_back();
        }
        
        for (auto& p : st) 
            answer += string(p.second, p.first);
        
        return answer;
    }
    
    /*
    //bad answer...
    // -> time limit Exceeded
    bool checkAndRemove(string& s, int k) {
        
        bool ret = false;
        
        int count = 1;
        
        for(int i = 1; i < s.size(); i++) {
            if(s[i-1] == s[i])
                count++;
            else
                count = 1;
            
            if(count == k) {
                //초기화
                count = 1;
                
                //remove prepare
                for(int a = 0; a < k; a++) {
                    s[i - a] = '#';
                }
                
                //return
                ret = true;
            }
        }
        
        //remove
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        
        return ret;
    }
    
    string removeDuplicates(string s, int k) {
        
        while(checkAndRemove(s, k));
        
        return s;
    }
    */
};