class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n == 0 || m == 0)
            return false;
        
        int l = 0;
        int r = m * n - 1;
        
        while(l <= r) {
            
            int mid = l + (r - l) / 2;

            int cur = matrix[mid / m][mid % m];
            
            if (target == cur)
                return true;
            else if(target < cur)
                r = mid - 1;
            else
                l = mid + 1;       
        }
        
        return false;
    }
};