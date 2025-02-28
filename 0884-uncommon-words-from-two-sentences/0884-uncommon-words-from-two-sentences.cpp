class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string, int> count;
        stringstream ss1(s1), ss2(s2);
        string word;

        while (ss1 >> word) {
            count[word]++;
        }

        while (ss2 >> word) {
            count[word]++;
        }

        vector<string> answer;
        for (auto& c : count) {
            if (c.second == 1) {
                answer.push_back(c.first);
            }
        }

        return answer;
    }
};