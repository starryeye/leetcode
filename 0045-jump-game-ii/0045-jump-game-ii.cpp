class Solution {
public:

    // 정수 배열 nums가 주어짐.
    //      각 요소는 해당 위치에서의 최대 점프 길이를 나타냅니다.
    //          반드시 최대로 점프안해도 됨.
    // 처음에는 배열의 첫 번째 인덱스에 위치

    // 마지막 인덱스에 도달가능하도록 배열이 주어진다.
    // 마지막 인덱스에 도달하기 위한 최소의 점프 횟수는?

/*
    // dp[i]
    //      상태 : i index 에 위치
    //      값 : 끝 인덱스에 도달하기 위한 최소의 점프 횟수
    int jump(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp(n, INT_MAX);

        // 초기화
        dp[n - 1] = 0; // 끝인덱스는 도달 하기 위해 0 번의 점프 필요
        
        for (int currentIdx = n - 2; currentIdx >= 0; currentIdx--) {
            
            int maxReachableIdx = min(currentIdx + nums[currentIdx], n - 1);

            for (int i = currentIdx; i <= maxReachableIdx; i++) {
                if (dp[i] != INT_MAX) {
                    dp[currentIdx] = min(dp[currentIdx], dp[i] + 1);
                }
            }
        }

        return dp[0]; 
    }
*/

    // dp[i]
    //      상태 : i index 에 위치
    //      값 : i index 에 도달하기 위한 최소 점프
    int jump(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp(n, INT_MAX);

        // 초기화
        dp[0] = 0; // 시작 인덱스
        
        for (int currentIndx = 0; currentIndx < n; currentIndx++) {

            int maxReachableIndx = min(currentIndx + nums[currentIndx], n - 1);

            for (int i = currentIndx + 1; i <= maxReachableIndx; i++) {
                dp[i] = min(dp[i], dp[currentIndx] + 1);
            }
        }

        return dp[n - 1]; 
    }
};