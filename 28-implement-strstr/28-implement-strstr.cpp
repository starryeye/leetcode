class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
        size_t ans = haystack.find(needle);
        
        if(ans != string::npos)
            return ans;
        else
            return -1;
    }
};