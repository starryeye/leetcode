
//로마숫자는 큰수에서 작은수로 표기되는게 규칙이란다.. 
// 해당 규칙 덕에 아래와 같은 for 문으로 계산가능
class Solution {
public:
    int romanToInt(string s) {
	
        unordered_map<char, int> mp = {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10}, 
            {'V', 5},
            {'I', 1}};
	
        //마지막 문자는 아래 for문에서 돌지 않고 미리 넣어둔다.
        int res = mp[s.back()];
	
        for(int i = 0; i < s.size() - 1; i++) 
        {
            if(mp[s[i]] < mp[s[i + 1]]) // IV 와 같은 케이스이다. (기존 규칙에 위배, 작은게 큰거보다 앞쪽에 위치)
            {
                res -= mp[s[i]];
            }
            else //일반적인 케이스이다.
                res += mp[s[i]];
        }
	
        return res;

    }
};