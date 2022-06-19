class Solution {
public:
    //O(n)
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int, int> um;
        
        for(auto num : nums) {
            
            if(!um[num])
                um[num]++;
            else
                um.erase(num);            
        }
        
        for(auto um : um) {
            return um.first;
        }
        
        return -1;
        
    }
    
    /*
    //O(nlogn)
    int singleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        // 요소가 1개인 경우는 for문 진입 못함
        for(int i=1; i < nums.size(); i+=2) {
            if(nums[i-1] != nums[i])
                return nums[i-1];
        }
        
        //요소가 1개있는경우
        //정렬후 마지막요소가 조건 만족하는 답일 경우
        return nums[nums.size()-1];
        
    }
    */
};