class Solution {
public:
    char findTheDifference(string s, string t) {
        
        unordered_map<char, int> um;

        for (char c : t) {
            um[c]++;
        }

        for (char c : s) {
            um[c]--;
        }

        for (auto& iter : um) {
            if (iter.second == 1)
                return iter.first;
        }

        return '?';
    }
};