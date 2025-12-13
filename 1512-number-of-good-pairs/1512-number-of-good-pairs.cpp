class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int answer = 0;

        unordered_map<int, int> count;

        for (int n : nums) {
            answer += count[n]++;
        }

        return answer;
    }
};