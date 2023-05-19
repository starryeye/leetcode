class Solution {
public:
    bool wordPattern(string pattern, string s) {



        vector<string> words;

        stringstream iss(s);
        
        string word;
        while (iss >> word)
            words.push_back(word);
      
        if (pattern.size() != words.size())
            return false;
        
        set<string> isExistWord;
        unordered_map<char, string> patternToWord;
        for (int i = 0; i < pattern.size(); i++) {
            
            char ch = pattern[i];
            
            if (patternToWord.find(ch) != patternToWord.end()) {
                if (patternToWord[ch] != words[i]) //기존 패턴인데 word가 다른 케이스
                    return false;
            }else {   
                if (isExistWord.count(words[i]) > 0) //새로운 패턴인데 word는 이미 있는 케이스
                    return false;
                
                patternToWord[ch] = words[i];
                isExistWord.insert(words[i]);
            }
        }
        return true;
    }
};