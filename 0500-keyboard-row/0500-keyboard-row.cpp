class Solution {

private:
    bool isContainsSameRow(string word, unordered_set<char>& set) {
        for(char ch : word) {
            if(set.find(tolower(ch)) == set.end()) {
                return false;
            }
        }

        return true;
    }
public:
    vector<string> findWords(vector<string>& words) {

        unordered_set<char> set1{'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> set2{'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> set3{'z','x','c','v','b','n','m'};
        vector<string> answer;
            
        for(string word : words) {

            if(set1.find(tolower(word[0])) != set1.end()) {
                if (!isContainsSameRow(word, set1))
                    continue;
            } else if(set2.find(tolower(word[0])) != set2.end()){
                if (!isContainsSameRow(word, set2))
                    continue;
            } else {
                if (!isContainsSameRow(word, set3))
                    continue;
            }
            
            answer.push_back(word);
        }
        
        return answer;
    }
};