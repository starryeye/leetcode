class Solution {
public:
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //예외 처리
        if (intervals.empty())
            return intervals;
        
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        
        answer.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            
            if (answer.back().back() < intervals[i].front()) //정상 그대로
                answer.push_back(intervals[i]);
            else // 역전
                answer.back().back() = max(answer.back().back(), intervals[i].back());
        }
        return answer;
    }
    
    /*
    //static 함수..
    static bool cmp(vector<int> a, vector<int> b) {
        return a.front() < b.front();
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //예외처리
        if(intervals.size() == 1)
            return intervals;
        
        vector<vector<int>> answer;
        
        //내부 정렬(x축)
        for(auto& inter : intervals) {
            sort(inter.begin(), inter.end());
        }
        
        //외부 정렬(첫 원소 기준, y축)
        sort(intervals.begin(), intervals.end(), cmp);
        
        //초기화
        answer.push_back(intervals[0]);
        
        //비교
        for(int i = 1; i < intervals.size(); i++) {
            
            //구간 겹침
            if(intervals[i-1][1] >= intervals[i][0]) {
                vector<int> temp;
                temp.push_back(answer.back()[0]);
                temp.push_back(max(intervals[i][1], intervals[i-1][1]));
                
                answer.pop_back(); //이전 원소 삭제
                answer.push_back(temp);
            } else {
                vector<int> temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                
                answer.push_back(temp);
            }
        }
        
        return answer;
    }
    */
};