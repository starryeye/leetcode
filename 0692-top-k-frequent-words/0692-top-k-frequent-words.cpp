class cmp {
public:
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
        if(a.second < b.second)
            return true;
        else if(a.second == b.second){
            if(a.first > b.first)
                return true;
        }
        
        return false;
    }
};


class Solution {
public:
    /*
    //이건 왜 안되지..
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        
        if(a.second < b.second)
            return true;
        else {
            if(a.first < b.first)
                return true;
        }
        
        return false;
    }
    */
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string> answer;
        
        unordered_map<string, int> um;
        
        for(auto w : words) {
            um[w]++;
        }
        
        //https://dbstndi6316.tistory.com/31
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        
        for(auto u : um) {
            pq.push({u.first, u.second});
        }
        
        for(int i = 0; i < k; i++) {
            pair<string, int> tmp = pq.top();
            pq.pop();
            
            answer.push_back(tmp.first);
        }
        
        return answer;
    }
};