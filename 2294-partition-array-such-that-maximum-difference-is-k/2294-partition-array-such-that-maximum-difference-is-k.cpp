class Solution {
public:
    //부분집합의 갯수를 찾는 문제..
    //각 부분집합의 최소/최대 값의 차이는 k를 넘어가면 안된다.
    //이러한 부분집합의 최소 갯수를 찾아라..
    int partitionArray(vector<int>& nums, int k) {
        
        //sort를 함으로써, 부분 집합의 최소/최대 값의 차이를 최소화 한다..
        sort(nums.begin(), nums.end());
        
        int maxNum = nums[0];//초기값 셋팅
        int minNum = nums[0];
        
        int answer = 1;
        
        for(auto n : nums) {
            maxNum = max(maxNum, n);
            minNum = min(minNum, n);
            
            //부분집합의 최소/최대 값의 차이가 k를 넘어가면..
            //또다른 부분집합이 필요하다..
            if(maxNum - minNum > k) {
                answer++;
                
                maxNum = n;//초기값 다시 셋팅
                minNum = n;
            }
        }
        
        return answer;
    }
};