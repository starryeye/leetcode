class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums2.size() == 1)
            return {-1};
        
        unordered_map<int, int> um;
        stack<int> stak;
        
        stak.push(nums2[0]);
        
        for(int i = 1; i < nums2.size(); i++) {
            
            while(!stak.empty()) {
                if(stak.top() < nums2[i]) {
                    um[stak.top()] = nums2[i];
                    stak.pop();
                }else
                    break;
            }
            
            
            stak.push(nums2[i]);
        }
        
        while(!stak.empty()) {
            um[stak.top()] = -1;
            stak.pop();
        }
        
        vector<int> answer;
        
        for(auto n : nums1) {
            
            answer.push_back(um[n]);
        }
        
        return answer;
        
    }
};