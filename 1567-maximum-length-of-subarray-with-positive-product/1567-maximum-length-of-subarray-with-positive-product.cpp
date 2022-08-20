class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int answer = 0;
        int negative = 0;
        int positive = 0;
        
        for(auto n : nums) {
            if(n == 0) {
                negative = 0;
                positive = 0;
            }else if(n < 0) {
                
                int cppos = positive;
                
                if(negative) //음수 곱 count 한게 있는 경우 음수에서 +1
                    positive = negative + 1;
                else        //음수 곱 count 한게 없는 경우
                    positive = 0; //negative도 현재 수치상 0 임..
                
                negative = cppos + 1;
            }else {
                positive++;
                
                if(negative) //음수 곱 count 한게 없는 경우 +1 못해준다.
                    negative++;
            }
            
            answer = max(answer, positive);
        }
        
        
        return answer;
    }
};