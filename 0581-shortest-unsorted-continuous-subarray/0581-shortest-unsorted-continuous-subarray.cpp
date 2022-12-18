class Solution {
public:
    /*
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> sortArr(nums.begin(), nums.end());
        
        sort(sortArr.begin(), sortArr.end());
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < nums.size() && sortArr[l] == nums[l])
            l++;
        
        while(r >= 0 && sortArr[r] == nums[r])
            r--;
        
        return l < r ? r - l + 1 : 0;
    }
    */
    
    //discuss
    int findUnsortedSubarray(vector<int>& N) {

        int len = N.size() - 1;

        int left = -1; //index 저장
        int right = -1;

        int maxN = N[0]; //left 방향에서 직전 index까지의 최댓값
        int minN = N[len]; //right 방향에서 직전 index까지의 최솟값

        //right는 바꿔야되는 범위의 가장 오른쪽 경계의 인덱스를 나타내고
        //-> i가 len 까지 증가 되는 중.. 가장 큰값보다 작은애가 갑자기 나타났다.. 그러면 right에 저장..
        //-> i가 len 까지 증가 되는 중.. 가장 큰값보다 큰애가 갑자기 나타났다.. 그러면 가장 큰값을 갱신해준다.
        // 
        //left는 바꿔야되는 범위의 가장 왼쪽 경계의 인덱스를 나타낸다..
        //right와 방향만 반대이고 최솟값으로 생각해보자..
        for (int i = 1; i <= len; i++) {

            int a = N[i];
            int b = N[len - i];

            if (a < maxN) 
                right = i;
            else 
                maxN = a;

            if (b > minN) 
                left = i;
            else 
                minN = b;

        }

        return max(0, right + left - len + 1);
    }
    
};