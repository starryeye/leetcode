class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) 
            return {};
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        //first window
        for(int i = 0; i < p_len; i++){
            
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        
        if(freq_p == window) // 벡터 비교로 Anagram 인지 판단한다.
            ans.push_back(0);
        
        for(int i=p_len;i<s_len;i++) {
            
            window[s[i-p_len] - 'a']--; //p와 갯수 맞추기 위해 -1 (가장 뒤에 것을 뺀다.)
            window[s[i] - 'a']++; //한칸 앞에 것을 넣어준다. +1
            
            if(freq_p == window) // 벡터 비교로 Anagram 인지 판단한다.
                ans.push_back(i-p_len+1);
        }
        
        return ans;
    }
};