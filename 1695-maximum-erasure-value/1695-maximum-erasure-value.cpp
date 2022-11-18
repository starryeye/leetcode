class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int answer = 0;
        
        int left = 0;
        int window = 0;
        
        unordered_set<int> us;
        
        
        for(int right = 0; right < nums.size(); right++) {
            
            while(us.find(nums[right]) != us.end()) {
                us.erase(nums[left]);
                window -= nums[left];
                left++;
            }
            
            us.insert(nums[right]);
            window += nums[right];
            
            answer = max(answer, window);
        }
        
        return answer;
    }
};