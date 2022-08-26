class Solution {
public:
    
    void dfs(string start, string end, unordered_map<string, vector<pair<string, double>>> um, unordered_set<string>& check, double mul, vector<double>& answer) {
        
        check.insert(start);
        
        if(start == end) {
            answer.push_back(mul);
        }
        
        for(auto v : um[start]) {
            
            if(check.find(v.first) != check.end())
                continue;
            
            dfs(v.first, end, um, check, mul * v.second, answer);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // A / B => A가 스타트, B가 엔드 인 DFS로 이동할때마다 value를 곱해준다.
        // 양방향 adj로 만들어준다.
        
        unordered_map<string, vector<pair<string, double>>> um;
        
        for(int i = 0; i < equations.size(); i++) {
            um[equations[i][0]].push_back({equations[i][1], values[i]});
            um[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        
        vector<double> answer;
        
        for(auto q : queries) {
            
            unordered_set<string> check;
            double mul = 1;
            int siz = answer.size();
            
            if(um.find(q[0]) != um.end())
                dfs(q[0], q[1], um, check, mul, answer);
            
            //can't find endpoint
            if(siz == answer.size())
                answer.push_back(-1);
        }
        
        return answer;
    }
};