class Solution {

    // 히터들과 집들의 x 좌표가 주어지면..
    // 모든 집들을 커버하는 히터의 최소 반경을 구하라..

public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin(), heaters.end());
        int answer = 0;

        for (int house : houses) {
            
            auto closest_heater_iter = lower_bound(heaters.begin(), heaters.end(), house);

            int house_heater_dist = (closest_heater_iter == heaters.end()) ? INT_MAX : *closest_heater_iter - house;
            int heater_house_dist = (closest_heater_iter == heaters.begin()) ? INT_MAX : house - *(closest_heater_iter - 1);

            answer = max(answer, min(house_heater_dist, heater_house_dist));
        }

        return answer;
    }

    // time limit 걸림..
    // int findRadius(vector<int>& houses, vector<int>& heaters) {
        
    //     // 히터와 집, 최소 거리 구하기
    //     vector<int> dist(houses.size(), INT_MAX);
    //     for (int i = 0; i < heaters.size(); i++) {
    //         for (int j = 0; j < houses.size(); j++) {
    //             dist[j] = min(dist[j], abs(heaters[i] - houses[j]));
    //         }
    //     }

    //     // 히터와 집, 최대 거리 구하기 (최소 거리 중..)
    //     int answer = 0;
    //     for (int i = 0; i < dist.size(); i++) {
    //         answer = max(answer, dist[i]);
    //     }

    //     return answer;
    // }
};