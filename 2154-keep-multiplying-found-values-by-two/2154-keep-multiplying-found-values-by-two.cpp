class Solution {
public:

    // 전체 시간 복잡도가 O(n) 로 보이지만, 해시 충돌이 일어나면, O(n^2) 일어날 수도?
    // int findFinalValue(vector<int>& nums, int original) {
        
    //     unordered_set<int> us;
    //     for (int& n : nums) {
    //         us.insert(n);
    //     }

    //     while(us.find(original) != us.end()) {
    //         original = original * 2;
    //     }

    //     return original;
    // }

    int findFinalValue(vector<int>& nums, int original) {
        
        sort(nums.begin(), nums.end());

        while(binary_search(nums.begin(), nums.end(), original)) {
            original *= 2;
        }

        return original;
    }
};