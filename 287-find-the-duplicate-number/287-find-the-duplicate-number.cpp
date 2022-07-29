class Solution {
public:
    
    /*
    // 도무지 이해가 안된다..
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;
        
        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low;
    }
    */
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        
        for(auto n : nums) {
            um[n]++;
            
            if(um[n] > 1)
                return n;
        }
        
        //의미 없음
        return nums[nums.size()-1];
    }
};