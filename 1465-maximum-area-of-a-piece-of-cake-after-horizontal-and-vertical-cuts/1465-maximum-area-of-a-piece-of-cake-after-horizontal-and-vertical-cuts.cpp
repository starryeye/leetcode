class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int h_max = max(horizontalCuts.front(), h - horizontalCuts.back()); //양끝 계산
        int w_max = max(verticalCuts.front(), w - verticalCuts.back()); //양끝 계산
        
        for(int i = 1; i < horizontalCuts.size(); i++) {
            h_max = max(h_max, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        
        for(int i = 1; i < verticalCuts.size(); i++) {
            w_max = max(w_max, verticalCuts[i] - verticalCuts[i - 1]);
        }
        
        return ((static_cast<long>(h_max) % 1000000007) * (static_cast<long>(w_max) % 1000000007)) % 1000000007;
    }
};