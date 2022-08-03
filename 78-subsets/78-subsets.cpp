class Solution {
public:
    //bit manipulation 풀이는 discuss 참고..
    void backtracking(vector<int> nums, int count, vector<int> add, vector<vector<int>>& answer) {
        
        answer.push_back(add);

        
        for(int i = count; i < nums.size(); i++) {
            add.push_back(nums[i]);
            backtracking(nums, i+1, add, answer);
            add.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> answer;
        vector<int> add;
        backtracking(nums, 0, add, answer);
        
        return answer;
    }
};