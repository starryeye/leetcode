class Solution {
public:
    bool isValid(unordered_map<char, int> s1Freq, unordered_map<char, int> s2Freq) {
        
        for(auto s : s1Freq) {
            if(s.second != s2Freq[s.first])
                return false;
        }
        
        //완벽하게 동일
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size())
            return false;
        
        unordered_map<char, int> s1Freq;
        unordered_map<char, int> s2Freq;
        
        int s1FreqSize = 0;//count의 총합
        int s2FreqSize = 0;//count의 총합
        
        for(auto s : s1) {
            s1Freq[s]++;
            s1FreqSize++;
        }
        
        int l = 0;
        int r = 0;
        
        for(; r < s2.size(); r++) {
            
            if(s1Freq.count(s2[r]) == 0) { //없음
                l = r + 1;
                s2Freq.clear();
                s2FreqSize = 0;
            }else { //있음
                
                //사이즈가 차이나면 넣어준다.
                if(s2FreqSize < s1FreqSize) {
                    s2Freq[s2[r]]++;
                    s2FreqSize++;
                }
                
                //저장 갯수 비교
                if(s2FreqSize == s1FreqSize) {
                    
                    //빈도 값 비교
                    if(isValid(s1Freq, s2Freq)) {
                        return true;
                    }else {
                        s2Freq[s2[l]]--;
                        s2FreqSize--;
                        l++;
                    }
                }
            }
        }
        
        return false;
    }
    /*
    //time limit...
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size())
            return false;
        
        unordered_set<string> us;
        
        sort(s1.begin(), s1.end());
        
        do {
            us.insert(s1);
        }while(next_permutation(s1.begin(), s1.end()));
        
        
        
        for(int i = 0; i < s2.size() - s1.size() + 1; i++) {
            string cmp(s2.begin() + i, s2.begin() + i + static_cast<int>(s1.size()));
            
            if(us.find(cmp) != us.end()) {
                return true;
            }
        }
        
        return false;
    }
    */
};