class Solution {
public:
    //check, sum은 &을 사용하지 않는다..
    //영원히 저장하지 않기 위해(dfs가 리턴되면 모든 값도 초기화)
    void dfs(int start, int end, vector<vector<int>>& graph, vector<bool> check, vector<vector<int>>& answer, vector<int> sum) {
        
        check[start] = true;
        sum.push_back(start);
        
        if(start == end) {
            answer.push_back(sum);
        }
        
        for(int i = 0; i < graph[start].size(); i++) {
            
            int next = graph[start][i];
            
            if(check[next] == true)
                continue;
            
            dfs(next, end, graph, check, answer, sum);
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<bool> check(graph.size(), false);
        vector<vector<int>> answer;
        
        dfs(0, graph.size() - 1, graph, check, answer, {});
        
        return answer;
    }
};