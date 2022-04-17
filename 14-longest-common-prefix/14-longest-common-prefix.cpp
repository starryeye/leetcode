class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string comp;
        int count = 0;
        
        for(int i = 0; i < strs[0].size(); i++)
        {
            count++;
            string tmp = strs[0].substr(0, count);            
            bool flag = true;
            
            for(int j = 1; j< strs.size(); j++)
            {
                if(tmp != strs[j].substr(0, count)) //다르면
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag) // 같다면
            {
                comp = tmp;
                
            }
            else // 다르면
            {
                count--;
                break;
            }
        }
        
        return comp;
        
    }
};