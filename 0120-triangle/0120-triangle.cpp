class Solution {
public:
    
    //discuss 참고하여 이해 해보기...
    // 훨씬 라인 수도 적고, 시간/공간 복잡도 면에서 나은듯..
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> dp;
        
        dp.push_back({triangle[0][0]});
        
        for(int i = 1; i < triangle.size(); i++) {
            
            dp.push_back({});
            
            for(int j = 0; j < triangle[i].size(); j++) {
                
                if(j == 0)
                    dp[i].push_back(dp[i-1][0] + triangle[i][0]);
                else if (j == triangle[i].size() - 1)
                    dp[i].push_back(dp[i-1][j-1] + triangle[i][j]);
                else
                    dp[i].push_back(min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]);
            }
        }
        
        return *min_element(dp.back().begin(), dp.back().end());
    }
};