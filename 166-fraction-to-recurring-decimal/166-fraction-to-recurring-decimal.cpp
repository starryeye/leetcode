class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        //분모 0, 예외처리
        if (!numerator) {
            return "0";
        }
        
        string ans;
        
        //음수, 예외처리
        if (numerator > 0 ^ denominator > 0) {
            ans += '-';
        }
        
        
        long n = labs(numerator);
        long d = labs(denominator);
        long r = n % d;
        
        ans += to_string(n / d);
        
        //소수점 없음, 예외처리
        if (!r) {
            return ans;
        }
        
        ans += '.';
        
        
        unordered_map<long, int> rs;
        
        while (r) {
            
            //반복 찾기
            if (rs.find(r) != rs.end()) {
                
                //반복구간 앞뒤로 ()
                ans.insert(rs[r], "(");
                ans += ')';
                break;
            }
            
            rs[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        
        return ans;
    }
};