class Solution {
public:
    // 흰색 공(0)은 왼쪽으로 검은 공(1)은 오른쪽으로
    // -> 흰색 공만 오른쪽으로 미는 비용 계산
    long long minimumSteps(string s) {
        
        int whiteEnd = 0; // 지금까지의 가장오른쪽 흰색 공 위치, left
        long long answer = 0;

        for (int i = 0; i < s.size(); i++) { // right

            if (s[i] == '0') {
                // 흰색공을 만나면, 지금까지의 가장오른쪽 흰색 옆으로 미는 비용 계산
                answer += i - whiteEnd;
                whiteEnd++; // 지금까지의 가장오른쪽 흰색 공 위치 갱신
            }
        }

        return answer;
    }
};