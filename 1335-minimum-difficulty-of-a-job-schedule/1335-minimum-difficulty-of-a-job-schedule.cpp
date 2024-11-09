class Solution {
public:

    // 문제
    // 작업의 순서는 바꿀수 없음
    // 하루에 하나의 작업은 반드시 수행
    // 하루에 수행한 작업의 난이도는 그날 작업중 최대 난이도
    // 스케쥴 난이도는 매일 수행한 작업난이도의 합
    // 작업 난이도 배열과 작업 일수가 주어질때.. 최소 스케쥴 난이도를 구해라

    // dp[d][i]
    //      상태 : d index 일 동안, i index 작업까지 수행함
    //      값 : 스케쥴 난이도 최소값
    // i index 작업을 언제 수행 시킬지 선택해야함
    //          1. i index 작업이 d - 1 index 일에 포함되어 수행되어도 난이도가 변하지 않음 (dp[d - 1][?] + ? ~ i 까지 난이도최대값)
    //          2. i index 작업이 d - 1 index 일에 포함되어 수행되어 난이도가 변함 (dp[d - 1][?] + difficult[i] -> 1번과 통합 가능)
    //          3. i index 작업이 d index 일에 포함되어 수행 (dp[d - 1][i - 1] + difficult[i])

    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size();

        if (n < d) return -1; // 작업 수가 일수보다 적다면 불가능

        // DP 배열 초기화
        vector<vector<int>> dp(d, vector<int>(n, INT_MAX));

        // 첫날 초기화, 0 index날 동안 0 index 작업만 수행
        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < n; ++i) {
            dp[0][i] = max(dp[0][i - 1], jobDifficulty[i]); // 0 index 일 동안, i index 작업까지 수행
        }

        // DP 배열 채우기
        for (int day = 1; day < d; ++day) { // 둘째날 부터 d번째날(d-1) 까지

            // i 는 index 이므로, 현재 전체 작업 개수는 i+1개 이다. 
            //      그래서 전체 일수도 index 이고 전체 일수가 day+1 이라면.. 
            //          i 는 최소 day 와 같아야한다. (day <= i)
            for (int i = day; i < n; ++i) { // day <= i < n
                
                int localMaxDifficulty = jobDifficulty[i]; // i index 작업 난이도로 시작
                dp[day][i] = INT_MAX;

                // j가 day 보다 크거나 같아야하는 이유..?
                // -> i index 작업을 어떤날에 할당할지.. 새로운 날, 바로 직전의날(편승)에 둘중 하나라고 생각
                // -> 근데.. 편승을 하는 날(j) 도 사실 day 보다 커야 하루에 하나씩의 작업을 최소한으로 수행하게된다.
                // j 는 i index 작업과 동일한 날에 수행되는 작업중 가장 난이도가 높은 작업 index 후보이다.
                for (int j = i; j >= day; --j) { // day <= j < i

                    localMaxDifficulty = max(localMaxDifficulty, jobDifficulty[j]);

                    dp[day][i] = min(dp[day][i], dp[day - 1][j - 1] + localMaxDifficulty);
                    // dp[day][i] : day 일 동안, i index 작업 까지를 수행 (총 작업난이도 최소 값)
                    // dp[day - 1][j - 1] + localMaxDifficulty
                    //      day-1 index 일 동안 j-1 index 작업까지 완료한 최소난이도값 + localMaxDifficulty
                    //              localMaxDifficulty : i index 작업부터 j index 작업까지(역순으로 탐색됨) 최대의 난이도
                    // 여기서 역순으로 for loop 를 돌린 이유가 나온다..
                    //      dp[day - 1][j - 1]
                    //          day-1 index 일 동안 j-1 index 작업까지 완료한 최소난이도값에..
                    //      localMaxDifficulty
                    //          day index 날에 j index 작업 부터 i index 작업까지의 최대 난이도를 더해야한다.
                    // 참고
                    // day index 날에 신규로 i index 작업만 할당되는 경우는..
                    // j == i 일때 고려된다..
                }
            }
        }

        return dp[d - 1][n - 1];
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