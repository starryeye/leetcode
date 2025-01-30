class Solution {

    // Solution 생성자로 주입한 배열의 index 를 반환하는 pickIndex 를 구현한다.
    // index 의 반환은 
    //      생성자로 주입한 원소 값을, 생성자로 주입한 배열 원소의 총합으로 나눈 확률로 반환한다.
    //      w[i] / sum_of_w 확률로 i 를 반환

private:
    vector<int> prefix_sum;

public:
    Solution(vector<int>& w) {
        
        prefix_sum.push_back(w[0]);

        for (int i = 1; i < w.size(); i++) {
            prefix_sum.push_back(prefix_sum[i - 1] + w[i]); // prefix sum
        }
    }
    
    int pickIndex() {
        
        int total_sum = prefix_sum.back();
        int n = rand() % total_sum + 1; // randomized

        auto iter = lower_bound(prefix_sum.begin(), prefix_sum.end(), n); // binary search

        return iter - prefix_sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */