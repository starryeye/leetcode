class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        
        long long answer = 0;
        
        int maxD = 0;
        
        for(auto d : damage) {
            answer += d;
            
            maxD = max(maxD, d);
        }
        
        return answer - min(armor, maxD) + 1;
    }
};