class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int answer = 0;
        
        /*
        //adj
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++) {
            if(manager[i] == -1) 
                continue;
            adj[manager[i]].push_back(i);
        }
        */
        
        //adj
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i < n; i++) {
            adj[manager[i]].push_back(i);
        }
        
        
        //bfs
        queue<pair<int, int>> que;
        
        que.push({headID, 0}); //l: id, r:accumulate time
        
        while(!que.empty()) {
            
            pair<int, int> cur = que.front();
            que.pop();
            
            for(auto next : adj[cur.first]) {
                
                int tmpTime = cur.second + informTime[cur.first];
                
                que.push({next, tmpTime});
                
                answer = max(answer, tmpTime);
            }
        }
        
        return answer;
    }
};