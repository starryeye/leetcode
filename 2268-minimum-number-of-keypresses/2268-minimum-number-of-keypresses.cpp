class Solution {
public:
    
    //key pad는 조건에만 맞으면 어떻게 만들어도 상관 없는 듯..
    int minimumKeypresses(string s) {
        
        int answer = 0;
        
        vector<int> frequency(26, 0);
        
        for(char c : s) {
            frequency[c - 'a']++;
        }
        
        sort(frequency.begin(), frequency.end(), greater<>());
        
        int count = 0;
        
        for(int i = 0; i < frequency.size(); i++) {
            
            if(i % 9 == 0)
                count++;
            
            answer += count * frequency[i];
        }
        
        return answer;
    }
};