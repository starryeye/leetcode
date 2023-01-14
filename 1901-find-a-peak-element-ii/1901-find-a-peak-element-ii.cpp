class Solution {
public:
    
    //162. Find Peak Element 와 관련된 문제
    //binary search : 한번의 로직으로 후보군의 반을 날리면 O(logN) 이다.. (밑이 2임!)
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        //mat.size() : n, mat[0].size() : m이라 치면,
        //어느 한 행에 대해 피크값 찾기의 시간복잡도는 logn이다.
        //그걸 모든 열에 대해 다 해준다면? n*logm 이 된다. (최악의 경우일때 시간복잡도임)
        //그럼 결과는 모든 행에 대한 피크값을 찾은 배열이 나옴.
        
        //하지만, 실제 문제 풀이법은 좀 다르다.
        
        int n = mat.size(); //행의 갯수
        int m = mat[0].size(); //열의 갯수
        
        int l = 0; //하나의 행의 초기 왼쪽 index
        int r = m - 1; //하나의 행의 초기 오른쪽 index
        
        
        //가로를 반으로 자르겠다는 의미
        while (l <= r) {
            
            int mid = l + (r - l) / 2;
            
            
            //mid 열의 최대 값을 가진 행 index
            int max_row = 0;
            for (int i = 0; i < n; ++i) {
                if (mat[max_row][mid] < mat[i][mid])
                    max_row = i;
            }
            
            
            if ((mid == 0 || mat[max_row][mid] > mat[max_row][mid - 1]) 
                && (mid == m - 1 || mat[max_row][mid] > mat[max_row][mid + 1])) //양끝이면 한쪽만.., 앙끝이 아니면 동쪽 서쪽 원소 보다 크면 피크
                return {max_row, mid};
            else if (mid > 0 && mat[max_row][mid - 1] > mat[max_row][mid]) //서쪽 원소 보다 작으면 
                r = mid - 1;
            else //동쪽 원소 보다 작으면
                l = mid + 1;
            
            //동쪽(서쪽도 동일) 원소 보다 작으 면의 각 의미에 대하여..
            //max_row인 원소가 동쪽 원소보다 작은 것이므로 mid 열의 모든 원소가 (max_row행, mid+1) 원소 보다 작은 의미가 되었다.
            //따라서 mid 열은 peak가 될 수 없다. 그래서 mid를 중심으로 서쪽 반을 날림
        }
        return {-1, -1};
    }
};