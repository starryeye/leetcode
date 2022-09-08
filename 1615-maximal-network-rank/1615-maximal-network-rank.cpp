class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        //adj
        vector<unordered_set<int>> adj(n);
        
        //building the graph, adjacency list
        for(auto r : roads) {
            adj[r[0]].insert(r[1]);
            adj[r[1]].insert(r[0]);
        }
        
        int maximal = 0;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                
                //sum neighbor of two citys
                int network_rank = adj[i].size() + adj[j].size();
                
                if(adj[i].find(j) != adj[i].end())
                    network_rank--;
                
                maximal = max(maximal, network_rank);
            }
        }
        
        return maximal;
        
    }
};