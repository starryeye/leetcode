#include <string>

class Solution {
public:
    
    //
    //discuss 보고.. 코드량 줄이기 + 다양한 접근법 보기(recursion(dfs), iterative, ...)
    //
    void combination(string digits, int index, vector<string>& answer, string pushing ) {
        if(index == digits.size()) {
            answer.push_back(pushing);
            return;
        }
        
        string tmp = "";
        
        tmp += digits[index];
        
        switch(stoi(tmp)) {
            case 2:
                for(int i=0; i<l2.size(); i++)
                    combination(digits, index+1, answer, pushing + l2[i]);
                break;
            case 3:
                for(int i=0; i<l3.size(); i++)
                    combination(digits, index+1, answer, pushing + l3[i]);
                break;
            case 4:
                for(int i=0; i<l4.size(); i++)
                    combination(digits, index+1, answer, pushing + l4[i]);
                break;
            case 5:
                for(int i=0; i<l5.size(); i++)
                    combination(digits, index+1, answer, pushing + l5[i]);
                break;
            case 6:
                for(int i=0; i<l6.size(); i++)
                    combination(digits, index+1, answer, pushing + l6[i]);
                break;
            case 7:
                for(int i=0; i<l7.size(); i++)
                    combination(digits, index+1, answer, pushing + l7[i]);
                break;
            case 8:
                for(int i=0; i<l8.size(); i++)
                    combination(digits, index+1, answer, pushing + l8[i]);
                break;
            case 9:
                for(int i=0; i<l9.size(); i++)
                    combination(digits, index+1, answer, pushing + l9[i]);
                break;
                
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> answer;
        
        //예외 처리
        if(digits.size() == 0)
            return answer;
        
        string pushing = "";
        
        combination(digits, 0, answer, pushing);
        
        return answer;
    }
    
    string l2 = "abc";
    string l3 = "def";
    string l4 = "ghi";
    string l5 = "jkl";
    string l6 = "mno";
    string l7 = "pqrs";
    string l8 = "tuv";
    string l9 = "wxyz";
    
};