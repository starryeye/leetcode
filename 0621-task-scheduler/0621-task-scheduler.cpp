class Solution {
public:
    //동일한 작업을 하려면.. 최소한 n의 시간 후에 다시 진행 할 수 있다..
    //작업이 주어질때 최소 걸리는 시간을 구하라..
    
    //https://leetcode.com/problems/task-scheduler/discuss/370755/C%2B%2B-solution-95-time-and-space-with-good-explanation
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> um;
        
        for (char c : tasks) {
            um[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        
        for(auto u : um) {
            pq.push({u.second, u.first});
        }
        
        //maxCount와 n만 있으면 최소 걸리는 시간이 정해진다.
        int maxCount = pq.top().first;
        int gap = n * (maxCount - 1); //gap 은 "남은 자리 수" 의 변수로 쓰임
        int total = maxCount + gap;
        
        pq.pop();
        
        while(!pq.empty()) {
            
            if(pq.top().first <= gap) { //남은 자리 수 내에 들어갈 갯수를 가졌다면...
                
                if(pq.top().first == maxCount) { //maxCount 와 동일한 갯수라면..
                    
                    gap -= pq.top().first - 1; //남은 자리 수에서 자리를 차지 할 만큼 빼줌
                    total++; //남은 자리 수에 못들어간 하나는 전체 걸리는 시간 + 1로 처리
                    
                }else { //maxCount 와 동일한 갯수가 아니면..
                    gap -= pq.top().first; //그냥 남은 자리수에서 자리를 차지 할 만큼 빼줌
                }
                
            }else { //남은 자리 수에서 넘친다..
                return tasks.size(); //그냥 주어진 tasks.size() 내에서 조합 하면 n을 만족하는 스케쥴을 만들 수 있다.
            }
            
            pq.pop();
        }
        
        return total;
    }
};