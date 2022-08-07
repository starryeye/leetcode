class Solution {
public:
    //https://leetcode.com/problems/k-closest-points-to-origin/discuss/221532/C%2B%2B-STL-quickselect-priority_queue-and-multiset
    //위 uri 참고하면 좋다.. 여러가지 방법이 있다..
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //멀티맵도 key로 정렬됨(기본 less)
        multimap<int, pair<int, int>> mm; //k: 거리제곱, v: 좌표
        
        for(auto i : points) {
            int dist = pow(i.front(), 2) + pow(i.back(), 2);
            
            //멀티맵은 이렇게 넣지 못함.
            //mm[dist] = {i.front(), i.back()};
            mm.insert({dist, {i.front(), i.back()}});
        }
        
        int count = 0;
        vector<vector<int>> answer;
        for(auto m : mm) {
            if(count == k)
                break;
            answer.push_back({m.second.first, m.second.second});
            count++;
        }
        
        return answer;
    }
};