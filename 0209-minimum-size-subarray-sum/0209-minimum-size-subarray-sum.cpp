class Solution {
public:
    //sliding window
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l = 0;
        int sum = 0;
        int answer = INT_MAX;
        
        for(int r = 0; r<nums.size(); r++) {
            
            sum += nums[r];
            
            while(target <= sum) { //target 보다 커서 조건을 만족하니까 왼쪽에서 하나씩 빼보자
                
                answer = min(answer, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
    
        return answer == INT_MAX? 0 : answer;
    }
    
    //prefix sum + two pointers
    /*
    int minSubArrayLen(int target, vector<int>& nums) {
        
        vector<int> prefixSum = {0};
        
        for (auto n : nums) 
            prefixSum.push_back(prefixSum.back() + n);
        
        if (prefixSum.back() < target)
            return 0;
        
        int answer = nums.size() + 1;
        int l = 0;
        int r = 1;
        
        while (r < prefixSum.size()) {
            
            if (prefixSum[r] - prefixSum[l] < target) {
                r++;
            }
            else {
                answer = min(answer, r - l);
                l++;
            } 
        }
        return answer;
    }
    */
    
    /*
    //prefix sum 과 two pointer로 풀어보려 했지만.. 못 풀었다..
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int answer = 0;
        
        int prefixSum = 0;
        
        for(auto n : nums)
            prefixSum += n;
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < r) {
            
            if(prefixSum < target)
                return nums.size() - (answer - 1); //바로 직전 loop 까지가 정답이라 -1
            
            if(nums[l] < nums[r]) {
                prefixSum -= nums[l];
                l++;
            }else {
                prefixSum -= nums[r];
                r--;
            }
            
            answer++;
                
        }
        
        return 0;
    }
    */
};