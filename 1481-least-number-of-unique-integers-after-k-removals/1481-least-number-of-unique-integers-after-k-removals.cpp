class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> um;
        
        for(auto a : arr) {
            um[a]++;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto u : um) {
            pq.push(u.second);
        }
        
        while(k > 0) {
            k -= pq.top();
            
            if(k >= 0)
                pq.pop();
        }
        
        return pq.size();
    }
};