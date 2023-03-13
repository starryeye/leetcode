class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        
        int answer = INT_MAX;
        
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        
        //s insert to map
        for(auto i : s) {
            um1[i]++;
        }
        
        //target insert to map
        for(auto t : target) {
            um2[t]++;
        }
        
        for(auto u : um2) {
            answer = min(answer, um1[u.first] / u.second);
        }
        
        return answer;
    }
};