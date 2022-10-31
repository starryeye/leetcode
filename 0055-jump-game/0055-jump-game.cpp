class Solution {
public:
    
     bool canJump(vector<int>& nums) {
         
         int max_arrival_index = nums[0] + 0; //도달가능한 최대 사거리 + 최대 사거리의 출발 인덱스
         
         for(int i = 1; i < nums.size(); i++) {
             
             //현재의 능력으로는 도달 불가능한 인덱스이다..
             if(max_arrival_index < i)
                 return false;
             
             //최대 사거리 및 인덱스 갱신
             if(max_arrival_index < nums[i] + i)
                 max_arrival_index = nums[i] + i;
         }
         
         return true;
     }
    
    
    /*
    -> 마지막 인덱스 도달 경우의 수...?
    bool canJump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 0);
        
        dp[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            
            for(int j = i + 1; j <= i + nums[i]; j++) {
                
                if(j > nums.size() - 1)
                    continue;
                
                dp[j] += dp[i];
            }
        }
        
        return dp[nums.size() - 1] > 0;
    }
    */
};
/*
-> dp(update)
class Solution {

    vector<int> memo;
    
    public:
    
    bool canJump(vector<int>& nums) {
    
        int n=nums.size();
        vector<int> dp(n,0);
        
        dp[0]=true;
        
        for(int i=1;i<n;i++){
        
             for(int j=i-1;j>=0;j--){
             
                 if(dp[j] && j+nums[j]>=i){
                     dp[i]=true;
                     break;
                 }       
             }           
        }
        
        return dp[n-1];
  }
};
*/