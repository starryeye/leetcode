class Solution {
public:
    //56-merge-intervals 문제랑 같이 볼 것..
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int answer = 0;
        
        map<int, int> mp;
        
        for(auto interval : intervals) {
            mp[interval.front()]++;
            mp[interval.back()]--;
        }
        
        int cur = 0;
        for(auto i : mp) {
            cur += i.second;
            answer = max(answer, cur);
        }
        
        return answer;
    }
};