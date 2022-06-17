class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minVal = 10000;
        
        int answer = 0;
        
        for(int i=0; i<prices.size(); i++) {
            minVal = min(minVal, prices[i]);
            
            answer = max(answer, prices[i]-minVal);
        }
        
        return answer;
    }
    
    
    /*
    //시간 초과
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<int> dp(n, 0);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] = max(dp[i], prices[i] - prices[j]); // dp[i]에서 얻을 수 있는 가장 높은 profit
            }
        }
        
        
        return *max_element(dp.begin(), dp.end());
    }
    */
};