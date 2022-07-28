class Solution {
public:
    /*
    //Discuss에 더 나은 시간복잡도를 가진 solution이 있는듯 하다..
    //시간될때 보자..
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        for(int i=m; i<nums1.size(); i++) {
            nums1[i] = nums2[i-m];
        }
        
        sort(nums1.begin(), nums1.end(), less<int>());
        
    }
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int a = m - 1; //nums1 숫자 부분의 가장 마지막 index
        int b = n - 1; //nums2 숫자 부분의 가장 마지막 index
        int i = m + n - 1; //nums1의 마지막 index
        
        //비어있는, nums1의 뒷부분 부터 채운다.
        while(a >= 0 && b >= 0) {
            
            if(nums1[a] > nums2[b])
                nums1[i--] = nums1[a--];
            else
                nums1[i--] = nums2[b--];
        }
        
        //남아있는 nums2 그대로 num1으로 채운다.
        //nums1은.. 그대로 nums1이므로 copy 불필요
        while(b >= 0)
            nums1[i--] = nums2[b--];
    }
};