class Solution {
public:
    
    //discuss.. 분석 필요
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        
        if (m < n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        
        vector<int> dp(n + 1);
        for (int i = 1; i <= m; i++) {
            
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                
                int curr = dp[j];
                if (nums1[i-1] == nums2[j-1]) {
                    
                    dp[j] = prev + 1;
                } else {
                    
                    dp[j] = max(dp[j-1], curr);
                }
                
                prev = curr;
            }
        }
        
        return dp[n];
    }
    
//     //배열에 중복이 없을 경우... 아래 풀이법 가능할 듯..
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
//         int answer = 0;
         
//         map<int, int> num1Indx;
//         for(int i = 0; i < nums1.size(); i++) {
//             num1Indx[nums1[i]] = i;
//         }
        
//         map<int, vector<pair<int, int>>> distPair;
//         for(int i = 0; i < nums2.size(); i++) {
            
//             if(num1Indx.find(nums2[i]) == num1Indx.end())
//                 continue;
            
//             int distance = abs(num1Indx[nums2[i]] - i);
            
//             if(distPair.find(distance) == distPair.end())
//                 distPair[distance] = {};
            
//             distPair[distance].push_back({num1Indx[nums2[i]], i});
//         }
        
//         vector<bool> capacity(500, false);
//         for(auto element : distPair) {
            
//             int length = element.first;
            
//             for(auto e : element.second) {
                
//                 bool check = false;
//                 for(int i = 0; i < length + 1; i++) {
                    
//                     if(capacity[e.first + i] == true)
//                         check = true;
//                 }
                
//                 if(check == true)
//                     continue;
                
//                 for(int i = 0; i < length + 1; i++) {
                    
//                     capacity[e.first + i] = true;
//                 }
                
//                 answer++;
//             }
//         }
        
//         return answer;
//     }
};