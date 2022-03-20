class Solution {
public:
    int climbStairs(int n) {
        //마지막 계단에서 생각해보면...
        //두가지로 나뉘어진다.
        //계단 한칸을 건너와서 마지막계단에 도착한 케이스
        //계단 두칸을 건너와서 마지막계단에 도착한 케이스
        //이 개념을 이용해보자.
        
        if(n == 0)
            return 1;
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        
        vector<int> climb(n+1, 0);
        
        climb[0] = 1;
        climb[1] = 1;
        climb[2] = 2;
        
        
        for(int i = 3; i<=n; i++)
        {
            climb[i] = climb[i-1] + climb[i-2];
        }
        
        return climb[n];
    }
};