class Solution {
public:
    //Distinct Characters
    //-> 고유 문자, "ece" 는 고유 문자로 만 따지면 2개이고 길이는 3이다.
    
    //discuss, hash map 사용하는 경우...
    //answerTmp 대신에 그냥 r - l 해버림.. 그러면 필요가 없음
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int answer = 0;
        
        unordered_map<char, int> um;
        
        int l = 0;
        
        int answerTmp = answer;
        
        for(int r = 0; r < s.size(); r++) {
            
            um[s[r]]++;
            answerTmp++;
            
            while(um.size() > k) {
                
                um[s[l]]--;
                answerTmp--;
                
                if(um[s[l]] == 0)
                    um.erase(s[l]);
                    
                l++;
            }
            
            answer = max(answer, answerTmp);
        }
        
        return answer;
    }
};