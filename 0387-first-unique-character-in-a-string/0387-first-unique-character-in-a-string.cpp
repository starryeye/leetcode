class Solution {
public:

    //2회차
    int firstUniqChar(string s) {

        unordered_map<char, vector<int>> um; //k: char, v: index

        for(int i = 0; i < s.size(); i++) {
            um[s[i]].push_back(i);
        }

        int answer = s.size();

        for(auto u : um) {
            if(u.second.size() == 1)
                answer = min(answer, u.second.front());
        }

        return answer == s.size() ? -1 : answer;
    }

    /*
    //discuss
    int firstUniqChar(string s) {
        vector<int> v(26,0);
		for(char c : s) v[c - 'a']++;
		for(int i = 0; i < s.length(); i++){
			if(v[s[i] - 'a'] == 1) return i;
		}
		return -1;
    }
    */
};