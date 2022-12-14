class Solution {
public:
    
    /*
    //오답
    static bool cmp(int a, int b) {
        string strA = to_string(a);
        string strB = to_string(b);
        
        while(strA.size() != strB.size()) {
            if(strA.size() > strB.size()) {
                strB += "0";
            }else if(strA.size() < strB.size()) {
                strA += "0";
            }
        }
        
        return strA > strB;
    }
    */
    
    static bool cmp(int a, int b) {
        string strA = to_string(a);
        string strB = to_string(b);
        
        return strA + strB > strB + strA;
    }
    
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), cmp);
        
        string answer;
        
        bool zeroFlag = true;
        
        for(auto n : nums) {
            answer += to_string(n);
            
            if(n != 0)
                zeroFlag = false;
        }
        
        if(zeroFlag == true)
            return "0";
        
        return answer;
    }
};