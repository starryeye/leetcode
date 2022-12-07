class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> que;
        que.push(beginWord);
        dict.erase(beginWord);
        
        int tick = 1;
        
        while (!que.empty()) {
            
            int n = que.size();
            
            for (int i = 0; i < n; i++) {
                
                string word = que.front();
                que.pop();
                
                if (word == endWord) {
                    return tick;
                }
                
                //dict.erase(word);
                
                for (int j = 0; j < word.size(); j++) {
                    
                    char c = word[j];
                    
                    for (int k = 0; k < 26; k++) {
                        
                        word[j] = 'a' + k;
                        
                        if (dict.find(word) != dict.end()) {
                            que.push(word);
                            dict.erase(word);
                        }
                     }
                    
                    word[j] = c;
                }
            }
            
            tick++;
        }
        
        return 0;
    }
    
    /*
    //time limit exceeded...
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> check;
        
        queue<string> que;
        que.push(beginWord);
        check.insert(beginWord);
        
        int tick = 0;
        
        while(!que.empty()) {
            int queSize = que.size();
            
            for(int a = 0; a < queSize; a++) {
                string cur = que.front();
                que.pop();
                
                if(cur == endWord)
                    return tick + 1;
                
                for(auto word : wordList) {
                    
                    if(check.find(word) != check.end())
                        continue;
                    
                    int diffCount = 0;
                    
                    for(int i = 0; i < word.size(); i++) {
                        if(word[i] != cur[i])
                            diffCount++;
                        
                        if(diffCount > 1)
                            continue;
                    }
                    
                    if(diffCount != 1)
                        continue;
                    
                    que.push(word);
                    check.insert(word);
                }
            }
            
            tick++;
        }
        
        return 0;
    }
    */
};