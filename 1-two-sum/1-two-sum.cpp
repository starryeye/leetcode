class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int, int> um; // k : value, v : index of nums
        
        for(int i = 0; i < nums.size(); i++) {
            um[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            
            int num = target - nums[i];
            
            if(um.find(num) != um.end() && um[num] != i) {
                ans.push_back(i);
                ans.push_back(um[num]);
                
                return ans;
            }
        }
        
        
        return ans;
    }
    /*
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        
        for(int i =0; i< nums.size() - 1; i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    
                    return ans;
                }
            }
        }
        
        return ans;
    }
    */
};