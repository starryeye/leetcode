class Solution {
public:
    //n-1 개의 요소를 1씩 증가시키는 것은..
    //1개의 요소를 1씩 감소 시키는 것과 동일하다. (Amazing)
    // 따라서.. 배열의 최솟값의 요소 만큼 뺀 배열의 요소들의 합이 정답이다.
    int minMoves(vector<int>& nums) {
        
        int answer = 0;
        
        int minNum = *min_element(nums.begin(), nums.end());
        
        for(auto n : nums) {
            answer += n - minNum;
        }
        
        return answer;
    }
};