class Solution {
public:
    /*
    //Time: O(N * N * logK)
    //Space: O(K)
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        
        int n = matrix.size();
        
        priority_queue<int> maxHeap; //priority_queue는 기본 maxHeap이다.
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                
                maxHeap.push(matrix[r][c]);
                
                if (maxHeap.size() > k) 
                    maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
    */
    
	int kthSmallest(vector<vector<int>>& matrix, int k)
	{
		int n = matrix.size();
        
		int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        
		int mid = 0;
        
		while (l < r)
		{
			mid = l + (r-l)/2;
			int num = 0;
            
			for (int i = 0; i < n; i++)
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
            
			if (num < k)
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		return l;
	}
};