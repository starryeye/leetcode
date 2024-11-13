class Solution {
public:
    // 서로다른 숫자를 가지는 여러개의 상자가 배열로 주어짐
    // 상자를 모두 삭제 할때 까지 반복
    // 동일한 숫자를 가지는 연속부분상자를 삭제하면 그 갯수의 제곱이 되는 점수를 획득
    // 점수를 최대화 하라..

    // dp[l][r][k]
    //      상태 : 구간 [l, r]에서 l 을 포함한 boxes[l]의 왼쪽에 k개의 동일한 색상의 연속된 박스가 있고 이를 모두 삭제한 상태
    //      값 : 최대 점수


    // 진짜 이해 안됨.. 어떻게 이렇게 생각을 할 수 있는건지도 모르겠고 코드를 봐도 잘 이해 안됨..
int removeBoxes(vector<int>& boxes) {

        int n = boxes.size();
    
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));

        // 구간 길이 1부터 n까지 순차적으로 채움
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l <= n - len; l++) {
                int r = l + len - 1;

                // 같은 색상의 연속된 박스를 포함시키기 위해 k를 증가
                for (int k = 0; k <= l; k++) {
                    int score = (k + 1) * (k + 1);
                    dp[l][r][k] = score; // l 을 포함하여 l 왼쪽에 k 개의 박스가 모두 동일하다고 가정하고 점수 계산

                    // (l+1 ~ r) 구간은 0 ~ l 구간과 별개로 생각한다. -> 초기값
                    if (l + 1 <= r) dp[l][r][k] += dp[l + 1][r][0];

                    // 구간을 나누어 최적 점수를 갱신
                    for (int m = l + 1; m <= r; m++) {
                        if (boxes[m] == boxes[l]) {
                            dp[l][r][k] = max(dp[l][r][k], dp[l + 1][m - 1][0] + dp[m][r][k + 1]);
                        }
                    }
                }
            }
        }

        // 전체 구간을 채우고, 최대 점수 반환
        return dp[0][n - 1][0];
    }
};