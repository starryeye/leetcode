/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    // 유명인 문제..
    //      n 명으로 구성된 집단이 있다.
    //      n 명 중, 한명의 유명인이 있으면 유명인의 index 반환, 없으면 -1 반환
    //      유명인..
    //          1. A 는 나머지 사람들을 모른다.
    //          2. 나머지사람들은 A 를 안다.
    //          (1, 2) 번 조건을 만족하는 A 를 유명인이라 한다.

    // 어떤 a 사람이 b 사람을 아는지 모르는지를 알려주는 함수 : bool knows(int a, int b)
    //      true 가 반환 되면.. (a 는 b 를 안다.)
    //          a 는 유명인이 아니다. (1 번 조건)
    //          b 는 유명인일 수 도 있다.
    //      false 가 반환 되면.. (a 는 b 를 모른다.)
    //          a 는 유명인일 수 도 있다.
    //          b 는 유명인이 아니다. (2 번 조건)
public:
    int findCelebrity(int n) {

        // 유일한 유명인 후보자 찾기
        // 두명을 비교하면 한명은 무조건 유명인이 아니다.
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }

        // 유명인 후보자가 유명인인지 검증
        for (int i = 0; i < n; i++) {

            if (i == candidate) continue; // 자기자신 비교 continue

            if (knows(candidate, i)) { // 1 번 조건 검증
                return -1;
            }
            
            if (!knows(i, candidate)) { // 2 번 조건 검증
                return -1;
            }
        }

        return candidate;
    }
};