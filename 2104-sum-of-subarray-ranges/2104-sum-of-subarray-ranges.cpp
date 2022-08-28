class Solution {
public:
    
    //O(n^3)
    //monotonic stack 풀이는 discuss 참조
    long long subArrayRanges(vector<int>& nums) {
        
        long long answer = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            
            int maxi = nums[i];
            int mini = nums[i];
            
            for(int j = i; j < nums.size(); j++) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                answer += maxi - mini;
            }
        }
        
        return answer;
    }
    
    /*
    //이방법으론 안되는듯..
    void dfs(vector<int>& nums, int index, vector<int>& sub, long long& sum) {
        
        //최초 공집합은 제외됨
        if(sub.size() > 0) {
            sum += sub.back() - sub.front();
        }        
        
        //input 1,2,3 에서 1,3이 선택된다..
        for(int i = index; i <= index + 1 && i < nums.size(); i++) {
            
            sub.push_back(nums[i]);
            
            dfs(nums, i+1, sub, sum);
            
            sub.pop_back();
            
        }
    }
    
    long long subArrayRanges(vector<int>& nums) {
        
        vector<int> sub;
        long long sum = 0;
        
        sort(nums.begin(), nums.end());
        
        dfs(nums, 0, sub, sum);
        
        return sum;
    }
    */
};