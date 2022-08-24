class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
       for(auto itr = remove(nums.begin(), nums.end(), 0); itr != nums.end(); itr++) {
           *itr = 0;
       }
    }
    
    /*
    //swap
    void moveZeroes(vector<int>& nums) {
        int last = 0, cur = 0;
    
        while(cur < nums.size()) {
            if(nums[cur] != 0) {
                swap(nums[last], nums[cur]);
                last++;
            }
        
            cur++;
        }
    }
    */
};