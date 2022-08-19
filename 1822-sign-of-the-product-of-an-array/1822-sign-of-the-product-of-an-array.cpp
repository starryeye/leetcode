class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int answer = 1;
        
        for(auto n : nums) {
            if(n > 0)
                answer *= 1;
            else if(n < 0)
                answer *= -1;
            else
                return 0;
        }
        
        return answer;
    }
};