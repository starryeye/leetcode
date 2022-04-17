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
    
    /*
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(str), end(str)); //정렬을 하면 사전순으로 정렬됨.
        string a = str[0];
        string b = str[n-1]; // 마지막 문자열과 첫번째 문자열을 비교하여 달라지는 부분이 정답이다.
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
        
    }
    */
};