class Solution {

private:
    vector<int> origin;
    unordered_map<int, vector<int>> um; // key: element of nums, value: index of nums

    int getRandomIndexOfUm(vector<int> &indexArr) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, indexArr.size() - 1);
        return dist(gen);
    }

public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            origin.push_back(nums[i]);
            um[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int randomIndexOfUm = getRandomIndexOfUm(um[target]);
        return um[target][randomIndexOfUm];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */