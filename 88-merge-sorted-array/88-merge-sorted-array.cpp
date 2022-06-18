class Solution {
public:
    //Discuss에 더 나은 시간복잡도를 가진 solution이 있는듯 하다..
    //시간될때 보자..
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        for(int i=m; i<nums1.size(); i++) {
            nums1[i] = nums2[i-m];
        }
        
        sort(nums1.begin(), nums1.end(), less<int>());
        
    }
};