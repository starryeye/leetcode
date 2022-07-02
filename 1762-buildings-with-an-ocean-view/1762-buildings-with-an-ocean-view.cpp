class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        vector<int> answer;
        
        int n = heights.size();
        
        int maxH = 0;
        
        for(int i = n-1; i >= 0; i--) {
            if(maxH < heights[i]) {
                answer.push_back(i);
                maxH = heights[i];
            }
        }
        
        sort(answer.begin(), answer.end(), less<int>());
        
        return answer;
    }
};