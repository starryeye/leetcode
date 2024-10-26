class Solution {
public:

    // 아직 이해안됨.. 이해 필요

    /**
     * @brief 작업 배열을 d일 동안 나누어 처리할 때 최소 난이도 합 계산
     * 
     * @param jobDifficulty 작업 난이도를 나타내는 배열
     * @param d 작업을 나눌 일 수
     * @return int 최소 난이도 합 (불가능할 경우 -1 반환)
     */
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        // 작업의 개수가 일 수보다 적으면 스케줄링 불가능
        if (n < d) return -1;

        // dp[i][j]: 첫 i개(0 index ~ i-1 index)의 작업을 j일 동안 처리할 때의 최소 난이도 저장
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX));

        // 초기 상태: 작업이 없을 때 (i=0, j=0) 난이도는 0
        dp[0][0] = 0;

        // DP 테이블 채우기: j일 동안 작업을 분배하는 경우를 탐색
        for (int j = 1; j <= d; ++j) {  // j일 동안
            for (int i = j; i <= n; ++i) {  // 첫 i개의 작업을 고려할 때
                int maxDifficulty = 0;  // 현재 구간의 최대 난이도

                // i번째 작업을 포함하는 구간의 최대 난이도를 찾음
                for (int k = i; k >= j; --k) {  // 역방향 탐색 (dp 테이블이 최대로 활용됨)
                    // 현재 구간(k ~ i)의 최대 난이도 갱신
                    maxDifficulty = max(maxDifficulty, jobDifficulty[k - 1]);

                    // dp[k-1][j-1]이 유효한 값이면 최소 난이도 합 갱신
                    if (dp[k - 1][j - 1] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + maxDifficulty);
                    }
                }
            }
        }

        // 최종 결과 반환: dp[n][d]가 INT_MAX이면 스케줄링 불가(-1 반환)
        return dp[n][d] == INT_MAX ? -1 : dp[n][d];
    }
};


/*
// 시간 초과 이다.. 아래는 n 의 d 제곱 시간복잡도를 가진다고 한다..

class Solution {
private:

    // 난이도 시작/끝 인덱스를 주면 난이도 중 가장 높은 난이도를 리턴
    int difficultyCalculate(int startIdx, int endIdx, vector<int>& jobDifficulty) {

        return *max_element(jobDifficulty.begin() + startIdx, jobDifficulty.begin() + endIdx + 1); //endIdx 위치의 원소는 포함되지 않아 + 1
    }

    // 주어진 스케쥴에 대해 난이도 합을 계산
    int difficultyAllCalculate(vector<pair<int, int>>& schedule, vector<int>& jobDifficulty) {

        int difficultySum = 0;

        for (auto& s : schedule) {
            int startIdx = s.first;
            int endIdx = s.second;

            difficultySum += difficultyCalculate(startIdx, endIdx, jobDifficulty);
        }

        return difficultySum;
    }

    // n 개의 job 을 d 일로 나누는 모든 경우(스케쥴)의 수를 backtracking 으로 찾고 해당 스케쥴에 대해 난이도 합의 최소를 찾는다.
    void backtrack(int d, int startIdx, vector<int>& jobDifficulty, vector<pair<int, int>>& schedule, int& answer) {

        if (d == schedule.size() + 1) { // 스케쥴 다짬
            schedule.push_back({startIdx, jobDifficulty.size() - 1});
            
            // 하나의 스케쥴에 대해 job difficulty 계산
            answer = min(answer, difficultyAllCalculate(schedule, jobDifficulty));

            schedule.pop_back();
            return;
        }

        for (int i = startIdx; i < jobDifficulty.size() - 1; i++) {

            schedule.push_back({startIdx, i});

            backtrack(d, i + 1, jobDifficulty, schedule, answer);

            schedule.pop_back();
        }
    }

public:

    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size();
        
        if (n < d) {
            return -1;
        }

        int answer = INT_MAX;
        int startIdx = 0;
        vector<pair<int, int>> schedule; // d 개의 원소로 이루어짐, 각 원소는 pair 로.. jobDifficutly 인덱스 시작/끝 으로 이루어짐

        backtrack(d, startIdx, jobDifficulty, schedule, answer);

        return answer;
    }
};
*/