class Solution {
public:
    //오른쪽 방향으로 k만큼 회전
    //rotate함수는 swap 기반의 함수이다. 따라서 원소가 많으면 좀 비효율적임..
    //rotate 함수는 인자로 (시작 반복자, 첫 위치로 올 Forward 반복자, 종료 반복자) 를 받는다.
    
    /*
    //1회차
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();
        
        std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
    }
    */
    
    //2회차
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();
        
        //두번째 파라미터는 end
        std::rotate(nums.begin(), nums.end() - k, nums.end());
    }
};