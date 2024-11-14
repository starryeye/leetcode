class Solution {
public:
    // 길이가 동일한 두개의 배열이 주어짐.
    // 한번의 "작업" 으로 nums1[i] 와 nums2[i] 를 교환

    // nums1 과 nums2 두 배열 모두 strictly increasing 배열로 만드는데 최소의 작업 횟수..

    // keep[i]
    //      상태 : i index 를 고려했는데 교환하지 않음
    //      값 : 최소의 작업 횟수..
    // swap[i]
    //      상태 : i index 를 고려했는데 교환함
    //      값 : 최소의 작업 횟수..
    int minSwap(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        
        vector<int> keep(n, INT_MAX);
        vector<int> swap(n, INT_MAX);

        keep[0] = 0;  // 첫 번째 원소를 교환하지 않은 상태의 초기값
        swap[0] = 1;  // 첫 번째 원소를 교환한 상태의 초기값

        for (int i = 1; i < n; ++i) {

            // Case 1: A[i] > A[i-1] and B[i] > B[i-1] (교환하지 않아도 되는 경우)
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                keep[i] = keep[i - 1];            // 이전 상태 유지
                swap[i] = swap[i - 1] + 1;        // 이전에 교환을 했기 때문에 교환을 해야 보정됨
            }
            
            // Case 2: A[i] > B[i-1] and B[i] > A[i-1] (현재 위치 교환 필요)
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                keep[i] = min(keep[i], swap[i - 1]);    // 이전에 교환한 후 현재 유지
                swap[i] = min(swap[i], keep[i - 1] + 1); // 이전에 유지한 후 현재 교환
            }
        }

        return min(keep[n - 1], swap[n - 1]);  // 마지막 인덱스에서 최소 교환 횟수
    }
};