class Solution {
public:
    // 요리사는 1시간안에 모든 요리를 완성할 수 있다.
    // 요리사는 n개의 요리에 대한 만족도를 배열로 가지고 있다.

    // like-time coefficient
    //      = time[i] * satisfaction[i] 으로 계산한다.
    //      여기서 time[i] 값은 요리 순서에 대한 누적 시간으로, 몇번째로 요리를 했는지로 생각해도 될듯..

    // 요리의 순서를 바꿀수 있고 요리를 몇개만 선택 가능하다..

    // like-time coefficient 의 최대 총합을 구하라..


    // 만족도가 높은 요리는 늦게 만들 수록 like-time coefficient 값이 올라간다..
    // dp[i][k]
    //      상태 : i "번째" 요리를 k번째(k time)로 고려
    //      값 : like-time coefficient 합계값(최대)
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();

        // 오름 차순 정렬
        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0)); // 왜 n+2?

        for (int i = n - 1; i >= 0; i--) { // 왜 n-1 에서 시작해서 0까지?(경계), 왜 역순으로?
            for (int t = 1; t <= n; t++) {

                dp[i][t] = max(dp[i + 1][t], dp[i + 1][t + 1] + t * satisfaction[i]);
                // max(dp[i - 1][t], dp[i - 1][t - 1] + t * satisfaction[i - 1])
                //      이렇게 안한이유는 i 를 역순으로 해서 그러는듯..
            }
        }

        return dp[0][1]; // 0 은 i 가 역순이니까? 인가.. 1은.. 왜..?
    }
};