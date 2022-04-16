class Solution {
public:
    //중복처리를 해결했다.. sort와 two point 개념을 도입하였다.
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }

        std::size_t n_size = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n_size; ++i) {
            // all numbers from now on will be greater than 0, no point in continuing
            if (nums[i] > 0) break;

            // we have seen this number & combo before; skip
            if (i > 0 and nums[i] == nums[i-1]) continue;

            int left = i+1, right = n_size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    int last_left = nums[left], last_right = nums[right];
                    // we have seen this number & combo before; skip
                    while (left < right && nums[left] == last_left) ++left;
                    while (left < right && nums[right] == last_right) --right;
                }
            }

        }
        return result;
    }
    
    /*
    //중복 처리가 어렵다...
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3)
            return {};
        
        int sum = 0;
        unordered_map<int, int> um; // key : nums, value : check
        
        vector<vector<int>> answer;
        
        for(int i = 0; i<nums.size(); i++)
            um[nums[i]]++;
        
       for(auto umTemp1 : um)
       {
           int key1 = umTemp1.first;
           
           um[key1]--;
           
           for(auto umTemp2 : um)
           {
               int key2 = umTemp2.first;
               
               if(um[key2] != 0)
               {
                   um[key2]--;
                   
                   sum = key1 + key2;
                   
                   if(um.count(sum * -1) && um[sum * -1] != 0)
                   {
                       answer.push_back({key1, key2, sum * -1});
                   }
                   
                   um[key2]++;
               }
           }
           
           um[key1]++;
           
       }
        
        return answer;
        
    }
    */
};