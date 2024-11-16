class Solution {
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
	    
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> memo(n, vector<int>(m, 0));
	    
        for (int j = 0; j < m; j++) {
            if(matrix[0][j] == '1') {
                memo[0][j] = 1;
            }
        }

        //finding height of  each cloumn in each row.
   	    for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(matrix[i][j] == '1') {
                    memo[i][j] = 1 + memo[i - 1][j];
                }
            }
        }

	    int ret = 0;
	    for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {

                int h = memo[i][j];
                for(int k = j; k < m; ++k){
				    h = min(h, memo[i][k]);
				    ret = max( ret, (k - j + 1) * h);
			    }
            }
        }
		    
	    return ret;
    }
};