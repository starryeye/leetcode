class Solution {
public:
    /*
    int minimumOperations(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int tmp = 0;
        
        int answer = 0;
        
        for(auto n : nums) {
            
            if(n != tmp) {
                answer++;
                tmp = n;
            }                
        }
        
        return answer;
    }
    */
    
    //정답..
    int minimumOperations(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        return s.size() - s.count(0);
    }
};