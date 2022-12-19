class Solution {
public:
    //programmers 고득점키트, 구명보트 문제..
    int numRescueBoats(vector<int>& people, int limit) {
        
        int answer = 0;
        
        sort(people.begin(), people.end());
        
        int l = 0;
        int r = people.size() - 1;
        
        //내가 정답을 맞추기 위해 count를 썻지만.. 왜 써야 정답인지는 분석 필요..
        int count = 0;
        
        while(l < r) {
            
            if(people[l] + people[r] > limit) {
                
                answer++;
                r--;
                count++;
            }else {
                
                answer++;
                r--;
                l++;
                count += 2;
            }
        }
        
        //answer에 포함되지 않은 사람들을 더해줌..
        return answer + people.size() - count;
    }
};