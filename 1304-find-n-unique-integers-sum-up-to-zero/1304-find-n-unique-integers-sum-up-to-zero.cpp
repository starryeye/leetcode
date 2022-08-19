class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> answer;
        
        
        for(int i = 1; i <= n/2; i++) {
            answer.push_back(i);
            answer.push_back(-i);
        }
        
        if(n % 2 == 1)
            answer.push_back(0);
        
        return answer;
    }
};