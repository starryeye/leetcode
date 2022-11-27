class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        unordered_set<string> us;
        
        string str = to_string(n);
        sort(str.begin(), str.end());
        
        //2의 30제곱 부터 10의 9제곱을 초과함
        for(int i = 0; i < 30; i++) {
            
            //pow의 return 은 실수형이다.
            string p = to_string(static_cast<int>(pow(2, i)));
            sort(p.begin(), p.end());
            us.insert(p);
        }
        
        if(us.find(str) != us.end())
            return true;
        else
            return false;
    }
};