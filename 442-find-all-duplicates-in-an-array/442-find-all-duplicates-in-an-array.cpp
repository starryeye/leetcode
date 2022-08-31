class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //We know that all numbers are positive, so we make the number negative to indicate that we saw it already.
        vector<int> res;
        int n = nums.size();
        
        for (int i = 0; i < n;i++) {
            int num = abs(nums[i]);

            if (nums[num-1] < 0) res.push_back(num);
            else nums[num-1] *= -1;
        }
        
        return res;
    }
    
    /*
    //brute force
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]!=nums[j])
                    continue;
                else{
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        return ans;
    }
    */
    /*
    //sorting
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<int>ans;
        sort(begin(nums),end(nums));
        int s = nums[0];
        for(int i=1;i<nums.size();i++){
            if(!(s^nums[i])){
                ans.push_back(nums[i]),i+=1;
                if(i<nums.size())s=nums[i];
                else break;
            }
                else s = nums[i];
        }
        return ans;
    }
    */
    /*
    //hash table
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int no:nums)mp[no]++;
        for(auto it:mp)if(it.second==2)ans.push_back(it.first);
        return ans;
    }
    */
};