class Solution {
public:

    // 정수 배열 arr가 주어졌을 때, 
    //      인덱스 i에서 시작하여 배열의 끝 인덱스 n-1까지 다음과 같은 규칙으로 점프할 수 있다.

    // 홀수 번째 점프에서는 현재 위치에서 이동할 수 있는 값 중 가장 작으면서 현재 값 이상인 인덱스로 이동
    // 짝수 번째 점프에서는 현재 위치에서 이동할 수 있는 값 중 가장 크면서 현재 값 이하인 인덱스로 이동

    // 더 이상 이동할 수 없는 경우 종료
    // 배열의 끝에 도달할 수 있는 초기 인덱스의 개수를 구하는 것이 목표

int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        // DP 배열을 통해 각 인덱스에서 시작했을 때 홀수/짝수 점프로 끝까지 도달 가능한지 추적
        vector<bool> odd(n, false), even(n, false);
        odd[n - 1] = even[n - 1] = true;  // 마지막 인덱스는 항상 끝에 도달 가능
        
        // TreeMap과 유사한 구조로 값을 키로, 인덱스를 값으로 저장하는 맵
        map<int, int> idx_map;
        idx_map[arr[n - 1]] = n - 1; // 마지막 인덱스부터 저장 시작
        
        int res = 1;  // 결과 값. 마지막 인덱스는 항상 도달할 수 있으므로 초기값은 1

        for (int i = n - 2; i >= 0; --i) { // 배열을 거꾸로 탐색
            // 홀수 점프(현재 값 이상 중 가장 작은 값 찾기)
            auto odd_jump = idx_map.lower_bound(arr[i]);  
            // 짝수 점프(현재 값 이하 중 가장 큰 값 찾기)
            auto even_jump = idx_map.upper_bound(arr[i]);

            // 홀수 점프 가능 여부 확인
            if (odd_jump != idx_map.end()) {
                odd[i] = even[odd_jump->second]; // 홀수 점프 시 다음 위치가 짝수 점프로 끝까지 도달 가능한지 확인
            }

            // 짝수 점프 가능 여부 확인
            if (even_jump != idx_map.begin()) {
                even[i] = odd[prev(even_jump)->second]; // 짝수 점프 시 다음 위치가 홀수 점프로 끝까지 도달 가능한지 확인
            }

            // 만약 해당 인덱스에서 시작한 홀수 점프가 끝까지 도달할 수 있다면 결과 값 증가
            if (odd[i]) { // 시작은 항상 홀수 점프이므로 odd[i] 인 경우만 res 를 증가시킨다.
                res++;
            }

            // 현재 값을 idx_map에 삽입하여 다음 인덱스 계산 시 사용
            idx_map[arr[i]] = i;
        }

        return res;
    }
};