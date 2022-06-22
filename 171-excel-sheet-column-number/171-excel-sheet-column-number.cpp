class Solution {
public:
    
    int powAlpha(int a, int c) {
        
        return pow(c, a);
    }
    
    int titleToNumber(string columnTitle) {
        
        int n = columnTitle.size();
        
        int answer = 0;
        
        for(int i=0; i<n; i++) {
            
            answer += powAlpha(n - 1 - i, 26) * (columnTitle[i] - 'A' + 1);
            
        }
        
        return answer;
    }
};