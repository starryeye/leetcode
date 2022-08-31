class Solution {
public:
    
    static bool cmp(string& s1, string& s2) {
        
        return s1.size() < s2.size(); //길이가 짧은 순서로 배치, 점점 길어지는 순서
    }
    
    int longestStrChain(vector<string>& words) {
        
        int answer = 0;
        
        unordered_map<string, int> dp;
        
        sort(words.begin(), words.end(), cmp);
        
        
        for(auto w : words) {
            
            dp[w] = 1; //기본값은 1이다.
            
            for(int i = 0; i < w.size(); i++) {
                
                string s = w.substr(0, i) + w.substr(i+1); //i인덱스 문자를 제외한 w의 substr
                
                if(dp.find(s) != dp.end()) {
                    
                    dp[w] = max(dp[w], dp[s] + 1);
                }
            }
            
            answer = max(answer, dp[w]);
        }
        
        return answer;
    }
};