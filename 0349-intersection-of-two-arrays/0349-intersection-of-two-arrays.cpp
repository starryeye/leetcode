class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> answer;
        
        unordered_set<int> us;
        
        for(auto i : nums1) {
            us.insert(i);
        }
        
        for(auto i : nums2) {
            if(us.find(i) != us.end()) {
                answer.push_back(i);
                us.erase(i);
            }
        }
        
        return answer;
    }
};