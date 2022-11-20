class Solution {
public:
    //어떻게 이 방법을 생각했을까... 
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(), properties.end(),
            [&](vector<int>& a, vector<int>& b) {
                if(a.front() < b.front()) //기본 오름차순
                    return true;
                else if(a.front() > b.front())
                    return false;
                else {
                    if(a.back() >= b.back()) //first 같을 경우엔 second 내림차순
                        return true;
                    else
                        return false;
                }
            });
        

        
        int answer = 0;
        int max_second = INT_MIN;
        
        for(int i = properties.size() - 1; i >= 0; i--) {
            
            if(properties[i][1] < max_second) {
                answer++;
            }
            
            max_second = max(max_second, properties[i][1]);
        }
        
        return answer;
    }
};