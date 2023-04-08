class Solution {
public:
    //discuss..
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int totalSize = rolls.size() + n;
        
        int totalValue = mean * totalSize;
           
        int targetValue = totalValue - accumulate(rolls.begin(), rolls.end(), 0);

        
        if(targetValue < n || targetValue > 6 * n)
            return {};
        
        //17 line ~ 22 line ... very smart
        int remain = targetValue % n;
        
        vector<int> answer(n, targetValue / n);
        
        for(int i = 0; i < remain; i++)
            answer[i] += 1;
        
        return answer;   
    }
};

//time limit..
//잘생각한것 같은데.. 시간초과이다. dp를 활용해서 n 회 주사위를 굴려서 나온 주사위 값 배열에서 찾는..
//중간에 가망없으면 무시하는 로직도 있음(validation)

// class Solution {
// private:
//     //targetValue: 목표값, n: 굴릴수있는 남은 횟수
//     bool validation(int targetValue, int n) {
//         //불가능
//         if(targetValue < n || targetValue > n * 6)
//             return false;
        
//         return true;
//     }
// public:
//     vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
//         int totalSize = rolls.size() + n;
        
//         int totalValue = mean * totalSize;
        
//         int targetValue = totalValue - accumulate(rolls.begin(), rolls.end(), 0);
        
//         if(validation(targetValue, n) == false)
//             return {}; //불가능
        
//         unordered_map<int, vector<vector<int>>> dp; //key: 주사위 굴린 횟수, value: 주사위 값 집합
        
//         dp[0] = {{}}; //init
        
//         //botom up
//         for(int i = 1; i <= n; i++) {
                
//             for(auto prev : dp[i - 1]) {
                
//                 for(int j = 1; j <= 6; j++) { //roll dice
                    
//                     vector<int> inputRolls = prev;
//                     inputRolls.push_back(j);
//                     int curSum = accumulate(inputRolls.begin(), inputRolls.end(), 0);
                    
//                     if(validation(targetValue - curSum, n - i) == false)
//                         continue;
                    
//                     dp[i].push_back(inputRolls);
//                 }
//             }
//         }
        
//         for(auto rolls : dp[n]) {
            
//             if(targetValue == accumulate(rolls.begin(), rolls.end(), 0))
//                 return rolls;
//         }
        
//         return {};
//     }
// };