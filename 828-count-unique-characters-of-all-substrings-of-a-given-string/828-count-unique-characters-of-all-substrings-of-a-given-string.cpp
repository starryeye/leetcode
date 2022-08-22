class Solution {
public:
    int uniqueLetterString(string s) {
        
        int n = s.size();

        int ret = 0;

        vector<long long> left(n, -1);
        vector<long long> right(n, -1);

        vector<long long> recentLeftIdx(26, -1);
        vector<long long> recentRightIdx(26, n);
    
        for(int i = 0; i < n; i++) {
        
            left[i] = i - recentLeftIdx[s[i] - 'A'];
            recentLeftIdx[s[i] - 'A'] = i;

            right[n - 1 - i] = recentRightIdx[s[n - 1 - i] - 'A'] - (n - 1 - i);
            recentRightIdx[s[n - 1 - i] - 'A'] = n - 1 - i;
        }

        for(int i = 0; i < n; i++) {
            ret = (ret + (left[i] * right[i]) % 1000000007) % 1000000007;
        }

        return ret;
    }
};