class Solution {
public:
    //prefix, hash map
    int maxSubArrayLen(vector<int>& nums, int k) { 
        
        int answer = 0;
        
        unordered_map<long, int> firstHit; //k: 합계, v: 그 합계가 나온 최초 인덱스
        
        firstHit[0] = -1; //nums[-1, 1, 1], k = 1 -> 답은 3이 나와야함.. 2 - (-1) = 3 
        
        long prefixSum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            prefixSum += (long) nums[i];
            
            if(!firstHit.count(prefixSum)) 
                firstHit[prefixSum] = i;
            
            if(firstHit.count(prefixSum - k)) 
                answer = max(answer, i - firstHit[prefixSum - k]);
            
        }
        
        return answer;        
    }
};