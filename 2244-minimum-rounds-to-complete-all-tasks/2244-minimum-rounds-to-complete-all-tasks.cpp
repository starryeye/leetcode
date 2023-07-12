class Solution {
public:
    
    // 동일한 레벨의 작업에 대해..
    // 1개 -> 불가능
    // 2개 -> 2 task * 1 로 처리
    // 3개 -> 3 task * 1 로 처리
    
    // 3k       개 -> 3 task * k 로 처리
    // 3k + 1   개 -> 3 task * (k-1) + 2 + 2 이므로 3 task * (k-1) + 2 task * 2 로, 총 k + 1 로 처리
    // 3k + 2   개 -> 3 task * k + 2 task * 1 로 처리, 총 k + 1 로 처리
    
    // 결론....
    // n 개의 동일한 task 가 있다면..
    // (n+2)/3 을 하면 최소 작업 횟수가 나온다.
    // +2 는 2개, 3개 에 대한 처리이며.. 동시에 3k + 1, 3k + 2 를 k + 1 로 처리까지 해주는 연산이다..
    
    int minimumRounds(vector<int>& tasks) {
        
        int answer = 0;
        
        unordered_map<int, int> um;
        
        for(int i = 0; i < tasks.size(); i++) {
            
            um[tasks[i]]++;
        }
        
        for(auto u : um) {
            
            if(u.second == 1)
                return -1;
            
            answer += (u.second + 2) / 3;
        }
        
        return answer;
    }
};