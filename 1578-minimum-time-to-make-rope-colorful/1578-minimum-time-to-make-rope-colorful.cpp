class Solution {
public:
    //연속적으로 동일한 색상의 풍선 중, 가장 비용이 비싼 풍선 빼고 다 지운다는 생각이다.
    int minCost(string colors, vector<int>& neededTime) {
        
        int answer = 0;
        
        for(int i = 1; i < colors.size(); i++) {
            
            if(colors[i] == colors[i-1]) {
                
                answer += min(neededTime[i], neededTime[i-1]); //둘중에 한놈은 반드시 지워야함.
                neededTime[i] = max(neededTime[i], neededTime[i-1]); //가장 비용이 비싼 풍선 하나만 남기기 위해서 데리고 간다.
            }
        }
        
        return answer;
    }
};