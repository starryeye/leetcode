class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int, vector<int>> um; //k: 값, v: index
        
        int maxDegree = 0;
        vector<int> maxValues;
        
        for(int i = 0; i < nums.size(); i++) {
            
            um[nums[i]].push_back(i);
            
            if(maxDegree < um[nums[i]].size()) {
                maxDegree = um[nums[i]].size();
                
                maxValues.clear();
                maxValues.push_back(nums[i]);
            }else if(maxDegree == um[nums[i]].size()) {
                maxValues.push_back(nums[i]);
            }
        }
        
        int answer = nums.size();
        
        for(auto m : maxValues) {
            answer = min(answer, um[m].back() - um[m].front());
        }
        
        return answer + 1;
    }
};