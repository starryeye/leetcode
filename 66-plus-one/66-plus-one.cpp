/*class Solution {
public:
    
    
    vector<int> plusOne(vector<int>& digits) {
        //digits의 자리수가 ... 100자리 까지 가능하므로.. 숫자로 만들생각은 하면 안된다...
        
        int n = digits.size();
        
        vector<int> ans;
        vector<int> temp;
        
        //초과분 저장
        int flag = 1;
        
        for(int i = n - 1; i >= 0; i--)
        {
            int tmp = (digits[i] + flag) % 10;
            temp.push_back(tmp);
            
            if(digits[i] + flag == 10)
                flag = 1;
            else
                flag = 0;
        }
        
        //마지막 초과분 넣기 (원본 벡터 범위를 넘어섬)
        if(flag == 1)
            temp.push_back(1);
        
        int m = temp.size();
        
        for(int i = 0; i < m; i++)
        {
            int tmp = temp.back();
            ans.push_back(tmp);
            temp.pop_back();
        }
        
        return ans;
        
    }
};*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size() - 1;
      
      for (int i = n; i >= 0; --i) { // traverse digits from the last element (least significant)
        // since we begin with the last digit, increasing that digit by one
        // results in overflow.  Therefore, all elements PRIOR to digits[0]
        // need to be considered since there may be additional nines between
        // digits[0], ... , digits[n].
        if (digits[i] == 9) {  
          digits[i] = 0;
        } else {  // current digit is not 9 so we can safely increment by one
          digits[i] += 1;
          return digits;
        }
      }
      // if the program runs to this point, each 9 is now a 0.
      // to get a correct solution, we need to add one more element with 
      // a value of zero AND set digits[0] to 1 (in the most significant position)
      // to account for the carry digit.
      digits.push_back(0);
      digits[0] = 1;
      return digits;
    }
};