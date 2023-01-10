class Solution {
public:
    
    //discuss에서는 backtraking이라 한다...
    void brute(string& s, vector<string>& answer, int indx) {
        
        if(indx == s.size()) {
            answer.push_back(s);
            return;
        }
            
        if('a' <= s[indx] && s[indx] <= 'z') { //소문자일 경우
            
            brute(s, answer, indx + 1); //소문자 그대로 진행
            
            s[indx] = 'A' + s[indx] - 'a';
            brute(s, answer, indx + 1); //대문자로 변경한 경우도 진행 시켜줌
            
        }else if('A' <= s[indx] && s[indx] <= 'Z') { //대문자일 경우
            
            brute(s, answer, indx + 1); //대문자 그대로 진행
            
            s[indx] = 'a' + s[indx] - 'A';
            brute(s, answer, indx + 1); //소문자로 변경한 경우도 진행 시켜줌
            
        }else {
            brute(s, answer, indx + 1); //문자가 아니면 그대로 진행
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        
        vector<string> answer;
        
        brute(s, answer, 0);
        
        return answer;
    }
};