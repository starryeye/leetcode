class Solution {
private:
    int sum(int n) {
        
        int result = 0;

        while (n > 0) {
            result += (n % 10);
            n /= 10;
        }

        return result;
    }

public:
    int countLargestGroup(int n) {
        
        unordered_map<int, int> group_size;

        int max_count = 0;
        for(int i = 1; i <= n; i++) {
            int sum_result = sum(i);
            group_size[sum_result]++;
            max_count = max(max_count, group_size[sum_result]);
        }

        int answer = 0;
        for(auto& g : group_size) {
            if (g.second == max_count) {
                answer++;
            }
        }

        return answer;
    }
};