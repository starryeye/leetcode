class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        //각 배열 합
        int sumA = accumulate (nums1.begin(), nums1.end(), 0);
        int sumB = accumulate (nums2.begin(), nums2.end(), 0);
    
        //예외 처리
        if (sumA == sumB) 
            return 0;
        
        //오름차순으로 변수 정렬
        if (sumA > sumB) {
            swap(nums1, nums2);
            swap(sumA, sumB);
        }
        
        //이만큼 차이가 나는 중이다.
        int dif = sumB - sumA;
        
        vector<int> v;
        
        //얼마나 바뀔수 있는지에 대한 배열, A는 합이 작기 때문에 더 높은 값으로 변해야 한다.
        for(auto &i : nums1)
            v.push_back(6-i);
        //얼마나 바뀔수 있는지에 대한 배열, B는 합이 크기 때문에 더 낮은 값으로 변해야 한다.
        for(auto &i : nums2)
            v.push_back(i-1);
        
        //얼마나 바뀔수 있는지에 대한 배열, 내림 차순으로 정렬한다.
        //많이 바뀔수있는 포텐셜을 가진 것을 먼저 바꾸어 보도록 한다.
        sort(v.rbegin(), v.rend());
        
        int answer = 0;
        for(int &i: v){
            
            answer++; // 포텐셜 하나당 한번으로 친다.
            
            dif = dif - i; //각 원소(포텐셜)만큼 차이를 줄인다.
            
            if(dif <= 0)  //포텐셜에 의해 차이가 줄게되면, 어느순간 0을 넘어서는 경우, 그때가 답이다.
                return answer;
			
        }
        return -1;
    }
};