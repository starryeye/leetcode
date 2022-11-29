class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        sort(arr.begin(), arr.end(),
            [&] (int a, int b) {
                if(abs(x - a) == abs(x - b)) {
                    return a < b;
                }else {
                    return abs(x - a) < abs(x - b);
                }
            });
        
        vector<int> answer(arr.begin(), arr.begin() + k);
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
    
    /*
    //Discuss 풀이..
assume A[mid] ~ A[mid + k] is sliding window

case 1: x - A[mid] < A[mid + k] - x, need to move window go left
-------x----A[mid]-----------------A[mid + k]----------

case 2: x - A[mid] < A[mid + k] - x, need to move window go left again
-------A[mid]----x-----------------A[mid + k]----------

case 3: x - A[mid] > A[mid + k] - x, need to move window go right
-------A[mid]------------------x---A[mid + k]----------

case 4: x - A[mid] > A[mid + k] - x, need to move window go right
-------A[mid]---------------------A[mid + k]----x------

//Using binary search
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    }
    */
    
    
};