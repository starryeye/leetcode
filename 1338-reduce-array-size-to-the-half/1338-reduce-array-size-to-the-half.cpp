class Solution {
public:
    
    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };
    // 이건 왜 안되는 거임..?
    // static bool cmp(pair<int, int> a, pair<int, int> b) {
    //     return a.second < b.second;
    // }
    
    
    //discuss에 bucket sort 풀이법( O(N)) 참고해볼것..
    //347번 문제와 비슷한 문제임.
    //아래는 O(NlogN)
    int minSetSize(vector<int>& arr) {
        //priority_queue<pair<int, int>, cmp> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        unordered_map<int, int> um;
        
        for(auto a : arr) {
            um[a]++;
        }
        
        for(auto u : um) {
            pq.push(u);
        }
        
        int answer = 0;
        int count = 0;
        int originSize = arr.size();
        
        while(!pq.empty()) {
            pair<int, int> t = pq.top();
            pq.pop();
            
            count += t.second;
            answer++;
            
            if(count >= originSize / 2)
                return answer;
        }
        
        return 0;
    }
};