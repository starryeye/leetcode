class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        int answer = 0;

        unordered_set<char> us;

        for (char& c : brokenLetters) {
            us.insert(c);
        }

        int brokenCount = 0;
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                
                if (brokenCount == 0) {
                    answer++;
                }

                brokenCount = 0;
            }

            if (us.find(text[i]) != us.end()) {
                brokenCount++;
            }
        }

        return answer;
    }
};