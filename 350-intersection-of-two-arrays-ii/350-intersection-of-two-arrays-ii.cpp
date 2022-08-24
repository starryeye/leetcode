class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> um;
        
        vector<int> answer;
        
        for(auto n : nums1) {
            um[n]++;
        }
        
        for(auto n : nums2) {
            if(um[n] > 0) {
                um[n]--;
                answer.push_back(n);
            }
        }
        
        return answer;
    }
};