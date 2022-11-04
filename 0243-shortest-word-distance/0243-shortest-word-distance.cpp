class Solution {
public:
    /*
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int answer = wordsDict.size();

        unordered_map<string, vector<int>> um;

        for(int i = 0; i < wordsDict.size(); i++) {
            um[wordsDict[i]].push_back(i);
        }

        for(int i = 0; i < um[word1].size(); i++) {
            for(int j = 0; j < um[word2].size(); j++) {

                answer = min(answer, abs(um[word1][i] - um[word2][j]));
            }
        }

        return answer;
    }
    */

    int shortestDistance(vector<string>& words, string word1, string word2) {
        int id1 = -1, id2 = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                id1 = i;
                if (id2 != -1) {
                    minDist = min(minDist, id1 - id2);
                }
            } else if (words[i] == word2) {
                id2 = i;
                if (id1 != -1) {
                    minDist = min(minDist, id2 - id1);
                }
            }
        }
        return minDist;
    }
};