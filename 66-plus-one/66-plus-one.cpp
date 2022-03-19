class Solution {
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
};