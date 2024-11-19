class Solution {
public:

    // 정수 배열 nums가 주어짐.
    //      각 요소는 해당 위치에서의 최대 점프 길이를 나타냅니다.
    // 처음에는 배열의 첫 번째 인덱스에 위치

    // 마지막 인덱스에 도달가능하면 true 리턴

    // dp[i]
    //      상태 : i index 에 위치
    //      값 : 도달 가능 여부
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();

        vector<bool> dp(n, false);

        // 초기화
        dp[0] = true; // 시작지점
        
        for (int i = 0; i <= n - 2; i++) {
            
            if (dp[i] == true && i + nums[i] <= n - 1) {
                dp[i + nums[i]] = true;
            }
        }

        return dp[n - 1];
    }
};