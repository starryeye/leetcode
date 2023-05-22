class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> answer;
        
        string temp = "";
        
        //left point 이동
        for(int l = 0; l < nums.size(); l++) {
            
            int r = l;
            
            //right point 이동
            while(r + 1 < nums.size() && nums[r + 1] == nums[r] + 1) {
                r++;
            }
            
            if(l < r) {
                temp += to_string(nums[l]);
                temp += "->";
                temp += to_string(nums[r]);
            }else {
                temp += to_string(nums[l]);
            }
            
            answer.push_back(temp);
            temp = "";
            l = r; //left point 이동
        }
        
        return answer;
    }
};