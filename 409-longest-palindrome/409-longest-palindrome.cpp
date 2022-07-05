class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> um;
        int answer = 0;
        
        for(int i =0; i<n; i++) {
            um[s[i]]++;
        }
        
        //int maxOdd = 0;
        bool odd = false;
        for(auto u : um) {
            if(u.second % 2 == 0) {
                answer += u.second;
            } else {
                //maxOdd = max(maxOdd, u.second ); 홀수 문자 한종류만 쓰는게 아니다..
                answer += u.second -1;
                odd = true;
            }
        }
        
        return odd ? answer + 1 : answer; //홀수중에 하나는 중앙으로
    }
};