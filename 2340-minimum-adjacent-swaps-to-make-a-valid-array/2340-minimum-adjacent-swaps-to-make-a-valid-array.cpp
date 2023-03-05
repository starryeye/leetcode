class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        
        // index return 됨.
        auto [minEl, maxEl] = std::minmax_element(nums.begin(), nums.end());
        
        int swaps = (minEl - nums.begin()) + (nums.end() - maxEl - 1);
        
        // 아래 조건이면 서로 바꿔지기 때문에 -1 해줘야한다.
        if(minEl > maxEl) 
            --swaps;
        
        return swaps;
    }
};