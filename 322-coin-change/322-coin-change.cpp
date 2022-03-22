//DP
//Knapsack Problem
//답이 곧 DP 배열이라 생각해보자
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int Max = amount + 1;
        vector<int> dp(amount+1, Max);
        
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j =0; j< coins.size(); j++)
            {
                if(coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
/*
//greedy
//not accept : coins = [100, 90, 1] amount = 385 (greedy : 100(3) + 90(0) + 1(85) -> 86, ans = 100(2) + 90(2) + 1(5) -> 9)
//time limit : ?
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0)
            return 0;
        
        int ans = 0;
        int n = coins.size();
        int leftAmount = amount;
        
        for(int i = n-1; i >= 0; i--)
        {
            if(leftAmount < coins[i])
                continue;
            while(leftAmount)
            {
                ans += leftAmount / coins[i];
                leftAmount = leftAmount % coins[i];
            }
        }
        
        if(leftAmount)
            return -1;
        
        return ans;
    }
};
*/