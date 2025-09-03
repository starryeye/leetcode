class Solution {
public:

    // prefix sum 원리 이용
    // 이진 배열 원소를 단순 더하면 1의 갯수를 세아리는 의미가 되지만..
    // 원소 "0" 을 -1 로 변경하게 되면..
    // prefix sum 이 0이 되는 두 index 차이가 답이된다..
    int findMaxLength(vector<int>& nums) {


        unordered_map<int, int> firstIndex; // k : prefixSum, v : index
        int sum = 0;
        int answer = 0;

        firstIndex[0] = -1; // 논리적으로 -1 index 에서 sum 이 0 이다.

        for (int i = 0; i < nums.size(); ++i) {

            sum += (nums[i] == 0 ? -1 : 1);

            if (firstIndex.count(sum)) {
                answer = max(answer, i - firstIndex[sum]);
            } else {
                firstIndex[sum] = i; // 최초 위치만 기록
            }
        }
        return answer;
    }
};