struct Job {
    int startTime;
    int endTime;
    int profit;
};

class Solution {
public:

    // dp[i][0]
    //      상태 : i 번째 job 까지 고려, 진행중인 job 없음
    //      값 : profit 최대 값
    // dp[i][1]
    //      상태 : i 번째 job 까지 고려, 진행중인 job 있음
    //      값 : profit 최대 값
    // -> 이렇게 해보려 했는데 어려움..

    // dp[i]
    //      상태 : i 번째 작업까지 고려
    //      값 : 최대 profit
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs;

        // 작업 정보를 저장
        for (int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        // endTime 기준으로 오름차순 정렬
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.endTime < b.endTime;
        });


        vector<int> dp(n, 0);

        // 초기화
        dp[0] = jobs[0].profit;

        for (int i = 1; i < n; ++i) {
            int currProfit = jobs[i].profit;

            // 현재 작업과 겹치지 않는 마지막 작업을 찾기
            int lastNonConflictingJobIndx = -1;
            for (int j = i - 1; j >= 0; --j) {
                if (jobs[j].endTime <= jobs[i].startTime) {
                    lastNonConflictingJobIndx = j;
                    break;
                }
            }

            // 현재 작업을 포함한 최대 이익 계산
            if (lastNonConflictingJobIndx != -1) {
                currProfit += dp[lastNonConflictingJobIndx];
            }

            // dp[i]는 이전까지의 최대 이익과 현재 작업을 포함한 이익 중 최대값
            dp[i] = max(dp[i - 1], currProfit);
            // dp[i - 1] : i 번째 작업은 선택하지 않음.
            // currProfit : i 번째 작업만 선택 or i 번째 작업을 포함한 최대 이익
        }

        // 마지막 작업까지 고려했을 때의 최대 이익 반환
        return dp[n - 1];
    }
};