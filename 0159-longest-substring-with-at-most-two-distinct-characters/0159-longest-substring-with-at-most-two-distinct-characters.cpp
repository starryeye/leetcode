class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int answer = 1;
        
        int l = 0;
        int r = 0;
        
        int curCount = 0;
        
        unordered_map<char, int> um; // k: char, v: count
        
        um[s[0]]++;
        curCount++;
        
        for(r = 1; r < s.size(); r++) {
            
            //새로운 종류 임.
            if(um.find(s[r]) == um.end()) {
                
                //현재 종류가 1개 이상이면 1개가 될때 까지 삭제시킨다.
                while(curCount > 1) {
                    um[s[l]]--;
                    
                    if(um[s[l]] == 0) {
                        um.erase(s[l]);
                        curCount--;
                    }
                    
                    l++;
                }
                
                curCount++;
            }
            
            //insert
            um[s[r]]++;
            
            answer = max(answer, r - l + 1);
        }
        
        return answer;
    }
};