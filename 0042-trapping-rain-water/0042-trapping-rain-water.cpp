class Solution {
public:
    
    //직관적 풀이법
    int trap(vector<int>& height) {
        vector<int> lMax(height.size());
        vector<int> rMax(height.size());

        int mL = 0;
        for(int i = 0;i<lMax.size();i++){
            mL=max(height[i], mL);
            lMax[i] = mL;
        }
        mL = 0;
        for(int i = lMax.size()-1;i>-1;i--){
            mL=max(height[i], mL);
            rMax[i] = mL;
        }
        
        int ans = 0;
        for(int i = 0;i<height.size();i++){
            ans += min(lMax[i],rMax[i])-height[i];
        }
        return ans;
    }
    
    /*
    //아래 discuss, solution 2 참조
    //https://leetcode.com/problems/trapping-rain-water/discuss/1374608/C%2B%2BJavaPython-MaxLeft-MaxRight-so-far-with-Picture-O(1)-space-Clean-and-Concise
    
    int trap(vector<int>& height) {
        
        if (height.size() <= 2) 
            return 0;
        
        int n = height.size();
        
        //two pointer
        int maxLeft = height[0];
        int maxRight = height[n-1];
        int left = 1;
        int right = n - 2;
        
        int ans = 0;
        
        
        while (left <= right) {
            
            if (maxLeft < maxRight) {
                
                if (height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    ans += maxLeft - height[left];
                
                left += 1;
                
            } else {
                
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    ans += maxRight - height[right];
                
                right -= 1;
                
            }
        }
        
        return ans;
    }
    */
};