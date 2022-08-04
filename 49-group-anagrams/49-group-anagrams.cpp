class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> answer;
        
        unordered_map<string, int> um; //k : string(sorted), v : index
        
        int index = 0;
        for(auto s : strs) {
            string strOrigin = s;
            sort(s.begin(), s.end(), less<char>());
            
            if(um.find(s) == um.end()) {
                answer.push_back({strOrigin});
                um[s] = index;
                index++;
            }else {
                answer[um[s]].push_back(strOrigin);
            }
        }
        
        return answer;
    }
};