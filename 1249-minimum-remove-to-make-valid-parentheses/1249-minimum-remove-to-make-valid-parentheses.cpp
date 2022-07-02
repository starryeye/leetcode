class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        //원소 : index
        stack<int> stak;
        
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '(') {
                stak.push(i);
            }else if(s[i] == ')') {
                if(!stak.empty()) {
                    stak.pop();
                } else {
                    s[i] = '*'; // 삭제되어야한다는 의미의 구분자
                }
            }
        }
        
        //스택에 남은 것들.. 삭제해야함
        while(!stak.empty()) {
            s[stak.top()] = '*';
            stak.pop();
        }
        
        //삭제될 것들 삭제
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        
        return s;
    }
};