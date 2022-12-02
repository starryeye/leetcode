class Solution {
public:
    //discuss 참조하여 다른 풀이는?
    
    //topological solution
    //topological solution 이란?
    //indegrees를 왜 써야하는거지?
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        queue<int> nodes;
        vector<int> indegrees(numCourses, 0);
        vector<int> result;
        
        for (auto item : prerequisites) {
            graph[item.back()].push_back(item.front());
            indegrees[item.front()]++;
        }
        for (int node_id = 0; node_id < indegrees.size(); ++ node_id) {
            if (indegrees[node_id] == 0) {
                nodes.push(node_id);
            }
        }
        while (!nodes.empty()) {
            
            int node_id = nodes.front();
            nodes.pop();
            result.push_back(node_id);
            
            for (auto neighber_id : graph[node_id]) {
                
                indegrees[neighber_id]--;
                if (indegrees[neighber_id] == 0) {
                    nodes.push(neighber_id);
                }
            }
        }
        
        return result.size() == numCourses ? result : vector<int>();
    }
    
    /* //내가 가진 알고리즘으로는 어려움..??????
    //dfs로는 어떻게 풀어야하지?
    void dfs(int start, int& count, vector<int>& answer, vector<int>& check, vector<vector<int>> adj) {
        check[start] = true;
        answer.push_back(start);
        count++;
        
        for(int i = 0; i < adj[start].size(); i++) {
            int next = adj[start][i];
            
            if(check[next] == true)
                continue;
            
            dfs(next, count, answer, check, adj);
        }
    }
    //bfs로는 어떻게 풀어야하지?
    void bfs(int start, int& count, vector<int>& answer, vector<int>& check, vector<vector<int>> adj) {
        check[start] = true;
        answer.push_back(start);
        count++;
        
        queue<int> que;
        
        que.push(start);
        
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            
            for(int i = 0; i < adj[cur].size(); i++) {
                int next = adj[cur][i];
            
                if(check[next] == true)
                    continue;
            
                check[next] = true;
                que.push(next);
                count++;
                answer.push_back(next);
                
            }
        }
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> answer;
        
        vector<vector<int>> adj(numCourses);
        
        //one way adj
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i = 0; i < numCourses; i++) {
            
            int count = 0;
            vector<int> check(numCourses);
            
            bfs(i, count, answer, check, adj);
            
            if(count == numCourses)
                return answer;
            else {
                answer.clear();
            }
        }
        
        return {0};
    }
    */
};