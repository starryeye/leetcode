class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        map<int, int> mp;
        
        for(auto i : intervals) {
            mp[i.front()]++;
            mp[i.back()]--;
        }
        
        int cur = 0;
        for(auto m : mp) {
            cur += m.second;
            if(cur >= 2)
                return false;
        }
        
        return true;
    }
};