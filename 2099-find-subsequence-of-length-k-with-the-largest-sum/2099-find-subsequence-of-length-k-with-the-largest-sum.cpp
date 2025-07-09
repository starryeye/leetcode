class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<pair<int, int>> numsWithIndex; // first : numsValue, second : numsIndex
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndex.push_back({nums[i], i});
        }

        // value 내림차순 정렬
        sort(
            numsWithIndex.begin(), 
            numsWithIndex.end(),
            [] (const pair<int, int>& a, const pair<int, int>& b) {
                return a.first > b.first;
            } 
        );

        // value 가 큰 top K 개 뽑기
        vector<pair<int, int>> topK(numsWithIndex.begin(), numsWithIndex.begin() + k);
        sort( // index 오름차순 정렬
            topK.begin(),
            topK.end(),
            [] (const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            }
        );

        vector<int> answer;
        for (auto& p : topK) {
            answer.push_back(p.first);
        }

        return answer;
    }
};