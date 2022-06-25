class Solution {
public:
    
    //한개의 원소를 바꿔서 감소하지 않는 배열을 만들 수 있는가?
    bool checkPossibility(vector<int>& nums) {
        
        int check = 0;
        
        //{3,4,2,3}
        //{4,2,3}
        for(int i=1; i<nums.size() && check <= 1; i++) {
            
            if(nums[i-1] > nums[i]){
                check++;
                
                if( i == 1 || nums[i-2] <= nums[i] )
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        
        return check <= 1;
    }
};