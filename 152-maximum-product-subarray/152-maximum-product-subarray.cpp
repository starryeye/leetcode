class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size(), minmax, maxmax;
        vector<int> dpmax(N), dpmin(N);
        
        dpmax[0] = dpmin[0] = minmax = maxmax = nums[0];
        
        for(int i = 1; i < N; i++)
        {
            //절대값으로 가장 큰 값들을 갱신한다.
            dpmax[i] = max(nums[i], max(dpmax[i-1]*nums[i], dpmin[i-1]*nums[i])); //양수
            dpmin[i] = min(nums[i], min(dpmax[i-1]*nums[i], dpmin[i-1]*nums[i])); //음수
            
            minmax = max(minmax, dpmin[i]);
            maxmax = max(maxmax, dpmax[i]);
        }
        return maxmax;
    }
};