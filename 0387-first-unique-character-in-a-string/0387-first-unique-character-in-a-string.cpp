class Solution {
public:
    //중복 제거
    int firstUniqChar(string s) {
        
        unordered_map<char, pair<int, int>> um;
        
        for(int i = 0; i < s.size(); i++) {
            um[s[i]].first++;
            um[s[i]].second = i;
        }
        
        int answer = s.size();
        
        for(auto u : um) {
            if(u.second.first == 1)
                answer = min(answer, u.second.second);
        }
        
        return answer == s.size() ? -1 : answer;
    }
    
    /*
    int firstUniqChar(string s) {
        
        unordered_map<char, int> um;
        
        for(int i = 0; i < s.size(); i++) {
            um[s[i]]++;
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(um[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
    */
};