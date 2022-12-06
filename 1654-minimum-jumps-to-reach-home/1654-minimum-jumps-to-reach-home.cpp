class Solution {
public:
    //https://leetcode.com/problems/minimum-jumps-to-reach-home/discuss/935384/C%2B%2B-BFS
    //왜 6000이어야 하는가? 수학적으로..? 분석 필요
    //visited를 2차원으로 한 이유를 모르겠음
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    
		unordered_set<int> forbi(forbidden.begin(), forbidden.end());
    
		vector<vector<int>> visited(2, vector<int>(6000));
		// visited array has two states:
		// visited[0][i] means the ith cell was reached from its left hand side jumping forward, 
		// visited[1][i] means the ith cell was reached from its right hand side jumping backward. 
    
		queue<pair<int, bool>> que; 
		// true means your last jump was backward jumping, you cannot jump backward in current step.
		// false, otherwise.
    
		que.push({0,false});
		visited[0][0] = 1;
		visited[1][0] = 1;
		int ans = 0;
    
		while(!que.empty()) {
            
			int len = que.size();
            
			while(len > 0) {
                
				len--;
				int cur = que.front().first;
				bool flag = que.front().second; //뒤로 두번 체크용
                que.pop();
                
				if(cur == x)
					return ans;
                
				
                
				int forward = cur + a;
				int backward = cur - b;
                
				if(forward < 6000 && visited[0][forward] == 0 && !forbi.count(forward)) {
                    
					que.push({forward, false});
					visited[0][forward] = 1;
				}
                
				if(backward >= 0 && visited[1][backward] == 0 && !forbi.count(backward) && !flag) {
                    
					que.push({backward, true});
					visited[1][backward] = 1;
				}
			}
            
			ans++;
		}
    
		return -1;
	}
};