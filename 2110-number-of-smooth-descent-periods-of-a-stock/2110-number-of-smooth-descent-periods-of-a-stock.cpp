class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        
        
        vector<long long> dp(prices.size(), 1);
        long long answer = dp[0];
        
        for(int i = 1; i < prices.size(); i++) {
            
            if(prices[i] + 1 == prices[i - 1]) {
                dp[i] += dp[i - 1];
            }
            
            answer += dp[i];
        }
        
        //answer = accumulate(dp.begin(), dp.end(), 0);
        
        return answer;
    }
};