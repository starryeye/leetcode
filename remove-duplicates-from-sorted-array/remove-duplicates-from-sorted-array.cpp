class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        
        //중복되지 않는 배열을 만들고있는 최종 포인터라고 생각하면 된다.
        int hand = 1;
        
        
        for(int i=1; i<n; i++)
        {
            if(nums[i-1] != nums[i]){
                nums[hand] = nums[i];
                hand++;
            } 
        }
        
        return hand;
    }
};