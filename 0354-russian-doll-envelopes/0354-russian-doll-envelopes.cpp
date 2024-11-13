class Solution {
public:
    // 봉투의 가로 세로 길이를 나타내는 envelopes 2차원 배열
    // 작업
    //      두 봉투를 비교했을 때, 가로 세로 길이 모두가 크면, 큰 봉투 안에 작은 봉투를 넣을 수 있다.

    // 작업을 했을 때, 사용된 봉투 최대 갯수는?

    // Longest Increasing Subsequence (최장 부분배열) 의 응용이라고 한다..
    // 두가지 요소에 대해 LIS 를 수행해야하는 상황이다.
    // 하나의 요소(가로) 는 정렬을 통해 고려 대상에서 제외 시키고..
    // 나머지 하나의 요소(세로) 로 LIS 를 수행하면 된다.


    static bool compare(vector<int>& a, vector<int>& b) {
        // 가로길이 오름차순 정렬 (가로 길이가 동일하다면 세로길이 내림 차순..)
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();
        
        // 가로길이에 대해 정렬하여 가로길이는 배제한다.
        sort(envelopes.begin(), envelopes.end(), compare);
        
        vector<int> temp;

        temp.push_back(envelopes[0][1]);

        // 세로 길이에 대해 LIS 수행..
        for (int i = 1; i < n; i++) { // envelopes[i] 를 순회하면 항상 가로길이는 이전보다 같거나 큼이 보장

            if (temp.back() < envelopes[i][1]) { 
                temp.push_back(envelopes[i][1]); // 가로 길이와 세로 길이 모두 크기 때문에 push_back
                // 가로를 오름차순으로 정렬했는데..
                // 가로가 동일할 경우 세로도 오름차순으로 정렬하면..
                // 해당 if 문에서 참이 되어 가로가 동일함에도 불구하고 push_back 이 되어 버린다.
                // 그래서 세로 길이는 가로길이가 동일할 경우.. 내림차순으로 정렬한다.
            } else {
                auto indx = lower_bound(temp.begin(), temp.end(), envelopes[i][1]) - temp.begin(); 
                // 이진 탐색 수행 (temp 는 정렬되어있음)

                temp[indx] = envelopes[i][1];
                // 여기 교체 과정은 LIS의 길이에는 영향을 주지 않지만, 더 작은 값으로 대체하여 나중에 더 긴 증가 수열을 형성할 수 있는 가능성을 열어줌..
                // 두가지가 있을듯..
                //      가로길이가 temp 마지막과 비교해서 동일한데 세로길이가 더 작아서 여기로 옴..
                //      가로길이가 temp 마지막과 비교해서 더큰데 세로길이가 더 작아서 여기로 옴..
            }
        }

        return temp.size();
    }
};