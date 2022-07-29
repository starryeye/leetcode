class Solution {
public:
    /*
    //hash map
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
    */
    //two pointers, floyd cycle detection
protected:
    int next(int n)
    {
        int sum = 0;
        
        while(n != 0)
        {
            sum += pow(n % 10,2);
            n = n / 10;
        }
        
        return sum;
    }
    
public:
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));
        
        //다르면 계속한다, 같아질때 까지...
        while(slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        
        //같아졌을때.. 그게 1인가..? 1이 아닌가...?
        return fast == 1 ;
    }
    
};