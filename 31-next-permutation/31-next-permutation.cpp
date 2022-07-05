class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //true이면 다음 순열로 변환됨, false면 최초 순열로 바꿔줌(뒤집기)
        next_permutation(nums.begin(), nums.end());
    }
};