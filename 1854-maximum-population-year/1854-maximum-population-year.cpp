class Solution {
public:
    //몰랐는데 아래 풀이법이 line sweep 이라고 한다..
    int maximumPopulation(vector<vector<int>>& logs) {
        
        map<int, int> m; //k: year, value: start->1, end->-1
        
        int cur = 0;
        int max = 0;
        int answer = 0;
        
        for(int i = 0; i < logs.size(); i++) {
            
            m[logs[i].front()]++;
            m[logs[i].back()]--;
        }
        
        for(auto i : m) {
            cur += i.second;
            
            if(cur > max) {
                max = cur;
                answer = i.first;
            }
        }
        
        return answer;
    }
};