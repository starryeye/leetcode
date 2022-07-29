class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int> um;
        
        int answer = 0;
        
        for(auto n : nums) {
            um[n]++;
        }
        
        for(auto m : um) {
            
            if(k == 0) {
                
                if(m.second > 1)
                    answer++;
            }else {
                
                if(um.find(m.first + k) != um.end())
                    answer++;
            }
        }
        
        return answer;
    }
};