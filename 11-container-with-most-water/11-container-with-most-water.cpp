class Solution {
public:
    int maxArea(vector<int>& height) {

        /* 시간 부족 O(n^2)
        int n = height.size();
        
        int ans = 0;
        
        for(int i =0; i<n-1; i++)
        {
            for(int j= i+1; j<n; j++)
            {
                int tmpArea = 0;
                if(height[i] <= height[j])
                {
                    tmpArea = (j - i) * height[i];
                }
                else
                {
                    tmpArea = (j - i) * height[j];
                }
                
                ans = max(ans, tmpArea);
            }
        }
        
        return ans;
        */
        
        //두개의 포인터가 서로를 향해 움직인다.
        //움직여야할 포인터를 "선택"하여...
        //O(n)
        
        int i= 0;
        int j= height.size() - 1;
        
        int ans = 0;
        
        while(i<j)
        {
            ans = max( ans, (j - i) * min(height[i], height[j]) );
            
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        
        return ans;
        
        
        //좀더 최적화
        //두 포인터의 높이 중, 높이가 낮은 포인터는
        //(움직일수록 가로 길이가 줄어들기때문에) 높이가 이전보다 높을때까지 포인터를 움직인다.
        /*
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
        */
        
        
        
    }
};