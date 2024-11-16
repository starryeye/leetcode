class Solution {
public:
    // 배열이 주어지면..
    // 배열에서 두개의 부분 배열을 만들어서 두 부분 배열의 원소들의 합이 동일하도록 한다. 
    //      두 부분 배열의 원소들은 서로 겹칠수 없음
    // 합의 최댓값은?

    // dp[i][k]
    //      상태 : 합이 k 가 되는 부분배열, i 번째 원소까지 고려
    //      값 : 경우의 수
    // -> 이렇게 하면.. 겹치는 원소가 발생가능함..
    //          [1, 2, 3, 4, 5] -> [1, 2, 3] & [1, 5]
    // -> 어떤 원소들이 포함 되어있는지 추적이 되어야하는데... (dfs 로 하면 될것 같기도 한데.. 안쓰는 방법 없나..)

    // dp[diff]
    //      상태 : 두 부분배열의 원소합 차이가 diff 이다.
    //      값 : 두 부분배열 원소합 중 큰 값(taller)
    // 즉, dp[taller - shorter] = taller

    // 설명 .. Editorial + lee
    int tallestBillboard(vector<int>& rods) {

        unordered_map<int, int> dp; // first : diff, second : taller
        
        // 초기화
        dp[0] = 0; // taller = shorter = 0
        
        for (int x : rods) { // rods 순회

            unordered_map<int, int> cur(dp);
            
            for (auto it: cur) { // dp 순회

                int diff = it.first;
                
                dp[diff + x] = max(dp[diff + x], cur[diff]);
                // x 를 큰쪽에 추가
                // ------- y ------|----- diff -----|----- x -----|  : dp[diff + x]
                // ------- y ------|                                 : cur[diff]
                
                dp[abs(diff - x)] = max(dp[abs(diff - x)], cur[diff] + min(diff, x));
                // x 를 작은쪽에 추가
                // x <= diff 인 경우
                // ------- y ------|----- diff -----|       : dp[abs[diff - x]]
                // ------- y ------|----- x -----|          : cur[diff] + x
                // or
                // x > diff 인 경우
                // ------- y ------|----- diff -----|       : cur[diff] + diff
                // ------- y ------|--------- x ---------|  : dp[abs[diff - x]]
            }

        }

        return dp[0];
    }
};