class Solution {
public:
    //2회차, 1회차와 비슷하나.. 1회차가 조금더 나음
    //discuss.. unordered_map<int, int> 를 두개 쓰면 단 한번의 for문으로 해결가능..
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> um;

        for(int i = 0; i < nums.size(); i++) {

            um[nums[i]].push_back(i);
        }


        int degreeMax = 0;
        int answer = 0;

        for(auto u : um) {

            if(degreeMax < u.second.size()) {

                degreeMax = u.second.size();

                answer = um[u.first].back() - um[u.first].front() + 1;
            }else if(degreeMax == u.second.size()) {

                answer = min(answer, um[u.first].back() - um[u.first].front() + 1);
            }
        }

        return answer;
    }
};