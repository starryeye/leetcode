class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        
        map<int, priority_queue<int>> m;

        for (auto i : items) {
            m[i[0]].push(i[1]);
        }

        vector<vector<int>> answer;

        for (auto& p : m) {

            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += p.second.top();
                p.second.pop();
            }

            answer.push_back({p.first, sum / 5});
        }

        return answer;
    }
};