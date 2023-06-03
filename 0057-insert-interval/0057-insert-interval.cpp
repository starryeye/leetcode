class Solution {
public:
    
    //아래는 newInterval 이 전체 interval 중간에 위치하는 경우도 되지만..
    //잘 생각해보면, newInterval 이 전체 interval 과 하나도 겹치지 않는 경우에도 동작함
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;
        
        for (int i = 0; i < intervals.size(); i++) {
			
            if (intervals[i][1] < newInterval[0]) {
                // intervals[i] 의 end 보다 newInterval 의 start 가 크다.
                // 겹치지 않으므로 interval 그대로 insert
                result.push_back(intervals[i]);
            }else if(intervals[i][0] > newInterval[1]) {
                // intervals[i] 의 start 보다 newInterval 의 end 가 작다.
                // 업데이트한 newInterval 을 넣고 현재 inteval 은 newInterval 에 넣어둔다.
                result.push_back(newInterval);
                newInterval = intervals[i]; 
            }else {
                // interval 과 newInterval 의 범위가 겹치는 경우이다.
                // 다음 interval 도 동일하게 겹칠 수 있으니 newInteval 에 업데이트 해놓는다.
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);

            }
        }
        
        //업데이트 때문에 한칸씩 밀렸으니.. 마지막으로 newInterval 을 넣고 끝낸다.
        result.push_back(newInterval);
        
        return result;
    }
};