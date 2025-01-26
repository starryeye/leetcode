class Solution {
public:
    string frequencySort(string s) {
        
        auto cmp = [](const pair<char, int> &a, const pair<char, int> &b) {
            return a.second < b.second; // 오름차순
        };

        // 큰게 top 이 됨.
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);

        unordered_map<char, int> um;
        for (auto c : s) um[c]++;

        for (auto entry : um) {
            pq.push(make_pair(entry.first, entry.second));
        }

        string answer = "";
        while(!pq.empty()) {
            
            auto e = pq.top();
            pq.pop();

            answer.append(e.second, e.first);
        }

        return answer;
    }
};