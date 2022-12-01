class Solution {
public:
    //time O(N)
    long long getDescentPeriods(vector<int>& prices) {
        
        
        vector<long long> dp(prices.size(), 1);
        long long answer = dp[0];
        
        for(int i = 1; i < prices.size(); i++) {
            
            if(prices[i] + 1 == prices[i - 1]) {
                dp[i] += dp[i - 1];
            }
            
            answer += dp[i];
        }
        
        //accumulate의 3번째 파라미터는 합의 초기 값이다.
        //해당 파라미터의 타입으로 합이 계산 되므로..
        //그냥 0으로 하면 int 타입의 범위를 벗어나면 쓰레기값..
        //0LL로 해줘야 long long 타입으로 된다.
        //answer = accumulate(dp.begin(), dp.end(), 0LL);
        
        return answer;
    }
    
    //space O(1)
    /*
    long long getDescentPeriods(vector<int>& prices) {
        int dp = 1;
        long long ans = 1;
        for(int i = 1; i < prices.size(); i ++) {
            if(prices[i] == prices[i - 1] - 1) {
                dp ++;
            } else {
                dp = 1;
            }
            ans += dp;
        }
        return ans;
    }
    */
};