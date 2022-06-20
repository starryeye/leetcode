class Solution {
public:
    //sort
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        return nums[nums.size() / 2];
    }
    
    /*
    //hash
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> um;
        
        for(auto num : nums) {
            if(++um[num] > nums.size() / 2)
                return num;
        }
        return -1;
    }
    
    //moore vote
    int majorityElement(vector<int>& nums) {
        
        int counter = 0;
        int answer;
        
        for(auto num : nums) {
            
            if(!counter)
                answer = num;
            
            counter += num == answer ? 1 : -1;
        }
        
        return answer;
    }
    */
};