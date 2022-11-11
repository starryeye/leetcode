class Solution {
public:
    /*
    //Discuss에 람다를 사용한 풀이법이 많은데 왜 안될까..
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), 
            [](const Interval& interval1, const Interval& interval2){
                return interval1.start < interval2.start;
            });
        
        for (int i = 1; i < intervals.size(); i++){
            
            if (intervals[i].start < intervals[i-1].end)
                return false;
        }
        
        return true;
    }
    */
    
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