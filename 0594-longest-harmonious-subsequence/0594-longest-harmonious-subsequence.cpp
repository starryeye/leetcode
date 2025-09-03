class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int, int> um;

        for (int num : nums) {
            um[num]++;
        }

        int answer = 0;

        for (auto& pair : um) {
            if (um.find(pair.first + 1) != um.end()) {
                answer = max(answer, pair.second + um[pair.first + 1]);
            }
        }

        return answer;
    }
};