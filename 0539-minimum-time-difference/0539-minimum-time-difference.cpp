class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> minutes(timePoints.size());

        for (int i = 0; i < timePoints.size(); i++) {
            int hour = stoi(timePoints[i].substr(0, 2));
            int minute = stoi(timePoints[i].substr(3));
            minutes[i] = hour * 60 + minute;
        }

        sort(minutes.begin(), minutes.end());

        int answer = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            answer = min(answer, minutes[i] - minutes[i - 1]);
        }

        int back_front_diff = (minutes.front() + 24 * 60) - minutes.back();
        answer = min(answer, back_front_diff);

        return answer;
    }
};