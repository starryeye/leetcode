class Solution {
public:
    //discuss에 Binary Search, Sliding Window 풀이법 찾아보기..
    //리뷰 완료..
    int minOperations(vector<int>& nums, int x) {
        
        int answer = nums.size() + 1;
        
        unordered_map<int, int> um; //k: prefix sum, v: count
        
        int prefix = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            
            if(prefix > x) //목표 값 보다 커지면 그만!
                break;
            
            um[prefix] = i + 1;
            
            if(prefix == x) //prefix만 사용해서 x가 될경우
                answer = min(answer, i + 1);
        }
        
        int suffix = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            suffix += nums[i];
            
            if(suffix > x) //목표 값 보다 커지면 그만!
                break;
            
            if(suffix == x) //suffix만 사용해서 x가 될경우
                answer = min(answer, (int)nums.size() - i);
            
            if(um.find(x - suffix) != um.end())
                answer = min(answer, ((int)nums.size() - i) + um[x - suffix]);
        }
        
        return answer == nums.size() + 1 ? -1 : answer;
    }
};