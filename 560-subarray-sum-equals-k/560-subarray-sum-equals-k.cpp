class Solution {
public:
    //prefix는 구간합을 의미 한다.
    // a ~ b index의 합을 구하려고 할때.. bruteforce로 풀면 시간 복잡도가 쌔다...
    // prefix로 미리 0 ~ a 까지의 부분합을 구해놓고 0~b 합에서 0~a 합을 빼는 식으로 하면 시간복잡도 O(n)..
    // prefix[i] - prefix[j] == k (i > j)
    int subarraySum(vector<int>& nums, int k) {
        
        int answer = 0;
        
        int n = nums.size();
        
        //prefix[i] : nums의 0 ~ i 인덱스까지의 합계(부분합)
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        
        //부분합 구하기
        for(int i = 1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        unordered_map<int, int> um; // first : 0 ~ i 까지의 prefix, second : 경우의 수
                
        
        for(int i = 0; i < n; i++) {
            
            //부분합 그자체로.. k
            if(prefix[i] == k)
                answer++;
            
            //구간합이 k인 경우 구하기
            if(um.find(prefix[i] - k) != um.end()) {
                answer += um[prefix[i] - k];
            }
            
            um[prefix[i]]++;
        }
        
        return answer;
        
    }
};