class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if (points.size() == 0) return 0;

        // x 축 end 좌표 기준으로 오름차순 정렬
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int answer = 1;
        int currentBalloonGroupEnd = points[0][1];
        // currentBalloonGroup : 한발로 터트릴수 있는 풍선 묶음의 x 축 마지막 좌표

        for (int i = 0; i < points.size(); i++) {

            int currentBalloonStart = points[i][0];
            int currentBalloonEnd = points[i][1];

            if (currentBalloonStart > currentBalloonGroupEnd) {
                // 한발로 터트리는 범위를 넘어섰음
                answer++;
                currentBalloonGroupEnd = currentBalloonEnd;
            }
        }

        return answer;
    }
};