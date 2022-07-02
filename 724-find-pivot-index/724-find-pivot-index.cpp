class Solution {
public:
    //한방에 해결하려 하지마라..............
    int pivotIndex(vector<int>& nums) {

        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        
        int leftSum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];
            
            if(leftSum == rightSum)
                return i;
            
            leftSum += nums[i];
        }
        
        return -1;
    }
    
    /*
    //중복을 해결 못함.. <int, unordered_map<int, int>> 쓰면 가능하긴함..
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        int answer = 1001;

        //first : sum, second : index
        unordered_map<int, int> sumA; //정방향
        unordered_map<int, int> sumB; //역방향

        int A = 0;
        int B = 0;

        sumA[0] = 0;
        sumB[0] = n - 1;

        for (int i = 0; i < n; i++) {

            A += nums[i]; //정방향 합계
            B += nums[n - 1 - i]; //역방향 합계

            sumA[A] = i + 1; //적재
            sumB[B] = n - 1 - (i + 1); //적재

            if (sumA.find(B) != sumA.end()) {

                if (sumA[B] == n - 1 - (i + 1))
                    answer = min(answer, n - 1 - (i + 1));

            }
            else if (sumB.find(A) != sumB.end()) {

                if (sumB[A] == i + 1)
                    answer = min(answer, i + 1);
            }
        }

        return answer == 1001 ? -1 : answer;
    }
    */
};