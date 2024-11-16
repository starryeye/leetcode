class Solution {
public:

    // target[i] - nums[i] -> diff[i] 를 응용하면..
    // 
    // 1526. Minimum Number of Increments on Subarrays to Form a Target Array 문제와 비슷해진다..
    // 

    long long minimumOperations(vector<int>& nums, vector<int>& target) {

        int n = nums.size();

        vector<long> diff(n, 0);

        for (int i = 0; i < n; i++) {
            diff[i] = target[i] - nums[i];
        }

        long operations = max(diff[0] , 0l);

        for (int i = 1; i < n; ++i) {
            
            operations += max(diff[i] - diff[i - 1], 0l);
        }
        
        return operations + max(-diff[n - 1], 0l);
        
    }
};