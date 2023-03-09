class Solution {
public:
    
    // return false if there is a circle
    bool dfs(int cur, const vector<vector<int>> & adj, vector<int> & vDepth, vector<int> & visitState) {
        
        if (visitState[cur] == 1)
            return true;  // 이전 그룹에서 방문했던 노드이므로 사이클이 아님.
        if (visitState[cur] == -1)
            return false; // 이번 그룹에서 방문했던 노드이므로 사이클 이다.
        
        visitState[cur] = -1; //현재 노드는 이번 그룹의 방문중 상태로 변경
        
        for (auto next : adj[cur]) {
            if (!dfs(next, adj, vDepth, visitState)) 
                return false;
            
            vDepth[cur] = max(vDepth[cur], 1 + vDepth[next]); // 재귀 리턴 되며... 누적 합이 됨.
        }
        
        visitState[cur] = 1; //visited; //끝까지 가보니까 사이클이 아님.
        return true;
    }
    
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        
        // visite state  -1:방문중;  0:방문안함;  1:방문했음
        vector<int> visitState(N, 0);
        
        // depth
        vector<int> vDepth(N, 1);
        
        // adj
        vector<vector<int>> adj(N);
        for (auto& v : relations) 
            adj[v[0] - 1].push_back(v[1] - 1);
        
        for (int i = 0; i < N; i++) 
            if (!dfs(i, adj, vDepth, visitState)) 
                return -1;
        
        return *max_element(vDepth.begin(), vDepth.end());
    }


    
    
    
    /*
    //Time Limit...
    // -> 사이클 찾기와 Output 찾기를 동시에 해야할듯..
    
    bool iscycle(vector<vector<int>> adj, vector<int> &vis, int cur) {
        
        if(vis[cur]==1)
            return true;
        
        if(vis[cur]==0)
        {
            vis[cur]=1;
            for(auto edge : adj[cur])
            {
                if(iscycle(adj, vis, edge))
                    return true;
            }
        }
        
        vis[cur] = 2;
        return false;
    }
    
    //check 를 쓰면, bfs의 경우 최단경로이므로 max가 안될수 있음..
    int bfs(int start, vector<vector<int>> adj) {
        
        queue<int> que;
        
        que.push(start);
        
        int tick = 0;
        
        while(!que.empty()) {
            
            int queSize = que.size();
            
            for(int a = 0; a < queSize; a++) {
                
                int cur = que.front();
                que.pop();
                
                for(int i = 0; i < adj[cur].size(); i++) {
                    int next = adj[cur][i];
                    
                    que.push(next);
                }
            }
            
            tick++;
        }
        
        return tick;
    }
    
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        vector<vector<int>> adj(n + 1);
        
        for(int i = 0; i < relations.size(); i++) {
            adj[relations[i][1]].push_back(relations[i][0]);
        }
        
        //사이클 찾기
        vector<int> vis(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            if(iscycle(adj, vis, i))
                return -1;
        }
        
        
        //Output 구하기        
        int answer = INT_MIN;
        
        for(int i = 1; i <= n; i++) {
            
            answer = max(answer, bfs(i, adj));
        }
        
        return answer;
    }
    */
};