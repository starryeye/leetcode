class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                sta.push(s[i]);
            }
            else
            {
                if(sta.empty())
                    return false;
                
                switch(s[i]) 
                {
                    case ')' :
                        if(sta.top() != '(')
                            return false;
                        sta.pop();
                        break;
                    case '}' :
                        if(sta.top() != '{')
                            return false;
                        sta.pop();
                        break;
                    case ']' :
                        if(sta.top() != '[')
                            return false;
                        sta.pop();
                        break;
                    default :
                        return false;
                }
            }
        }
        return sta.empty();
    }
};