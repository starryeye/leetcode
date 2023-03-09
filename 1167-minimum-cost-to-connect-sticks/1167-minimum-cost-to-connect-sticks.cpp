class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        int answer = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto s : sticks) {
            pq.push(s);
        }
        
        while(pq.size() != 1) {
            
            int first = pq.top();
            pq.pop();
            
            int second = pq.top();
            pq.pop();
            
            pq.push(first + second);
            
            answer += first + second;
        }
        
        return answer;
    }
};