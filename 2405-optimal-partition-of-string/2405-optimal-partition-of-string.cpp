class Solution {
public:
    int partitionString(string s) {
        
        int answer = 1; //최초에 이미 한 묶음이다.
        
        unordered_set<char> us;
        
        for(int i = 0; i < s.size(); i++) {
            if(us.count(s[i]) != 0) {
                answer++;
                us.clear();
            }
            us.insert(s[i]);
        }
        
        return answer;
    }
    ////최적화를 하려고 했던게 오히려.. 부분집합이 늘어난 꼴이다.
    // "shkqbyutdvknyrpjof"
//     int partitionString(string s) {
        
//         int answer = 1; //최초에 이미 한 묶음이다.
        
//         unordered_set<char> us;
        
//         int l = 0;
        
//         for(int r = 0; r < s.size(); r++) {
            
//             if(us.count(s[r]) != 0) {
//                 while(us.count(s[r]) != 0) { //최적화
//                     us.erase(s[l]);
//                     l++;
//                 }
                
//                 answer++;
//             }
            
//             us.insert(s[r]);
//         }
        
//         return answer;
//     }
};