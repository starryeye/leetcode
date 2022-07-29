class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int, int> um;
        
        while(n != 1) {
            
            //cycle
            if(um.find(n) != um.end())
                return false;
            else
                um[n]++;
            
            int tmp = n;
            int sum = 0;
            while(tmp) {
                int cur = tmp % 10;
                sum += pow(cur, 2);
                tmp = tmp / 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};