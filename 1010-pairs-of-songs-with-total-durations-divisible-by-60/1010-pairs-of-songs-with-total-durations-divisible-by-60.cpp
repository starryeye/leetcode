class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int answer = 0;
        
        unordered_map<int, long> um;
        
        for(auto t : time) {
            um[t % 60]++;
        }
        
        for(auto u : um) {
            
            if(u.first > 30) //이 조건문을 하지 않으려면.. 짝에 해당하는 원소를 erase해야하는데 for문에서는 erase하기 쉽지 않음
                continue;
            
            if(u.first == 0 || u.first == 30) {
                answer += u.second * (u.second - 1) / 2;
            }else {
                if(um.find(60 - u.first) == um.end())
                    continue;
            
                answer += u.second * um[60 - u.first];
            }

        }
        
        return answer;
    }
};