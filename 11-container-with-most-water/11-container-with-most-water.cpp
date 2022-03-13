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
        
        
        
    }
};