class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        sort(arr.begin(), arr.end(),
            [&] (int a, int b) {
                if(abs(x - a) == abs(x - b)) {
                    return a < b;
                }else {
                    return abs(x - a) < abs(x - b);
                }
            });
        
        vector<int> answer(arr.begin(), arr.begin() + k);
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};