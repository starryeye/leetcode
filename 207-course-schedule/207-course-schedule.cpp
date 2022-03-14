/*
class Solution {
public:
    void dfs(int start)
    {
        um[start] = true;
        
        for(int i =0; i < adj[start].size(); i++)
        {
            int next = adj[start][i];
            
            if(um.find(next) == um.end())
            {
                dfs(next);
            }
            else
            {
                flag = false;
            }
        }
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        if(prerequisites.empty())
            return true;
        
        //사이클이 있는지 찾는 문제
        
        //adj 생성
        adj = new vector<int>[numCourses];
        
        //adj 초기화
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        //이렇게 하면 [0, 1] 에서 잘못됨.
        //0으로 들어가서 check를 해버리고, 1에서 cycle이라고 해버림
        // -> 이건 adj의 0번째 인덱스(start, prere의 2번째인덱스)만 돌려보면됨.
        //그러나 [0, 1], [1, 2] 를 해결하지 못한다.
        // -> 1로 들어가서 cycle없다고 판단후, 2로 들어가서 1을 방문하며 cycle이 있다고 판단해버림.
        // -> 정답과 같이... 상태를 구분해줘야한다.
        for(int i = 0; i < numCourses; i++)
        {
            if(um.find(i) == um.end())
            {
                dfs(i);
                
                if(flag == false)
                    return false;
            }
        }
        
        return true;
    }
    
private:
    vector<int>* adj;
    unordered_map<int, bool> um;
    bool flag = true;
    
};
*/

class Solution {
public:
    // 0은 방문하지 않음, 1은 방문 중, 
    // 2는 해당 방문 노드는 방문할 필요가 없으며, cycle이 없다라고 알려줌(재귀를 빠져나오며...)
    
    bool iscycle(vector<int> adj[],vector<int> &vis,int id)
    {
        if(vis[id]==1)
            return true;
        
        if(vis[id]==0)
        {
            vis[id]=1;
            for(auto edge : adj[id])
            {
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        
        vis[id] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        //adj 생성
        vector<int> adj[n];
        
        //adj 초기화
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        
        //방문 check 
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
};