class Solution {

private:
    vector<int> parent;  // 각 인덱스의 부모를 저장하는 배열

    // find 함수: x가 속한 그룹의 대표(루트)를 찾음
    // 경로 압축(path compression)도 함께 해서 나중에 더 빨라짐
    int find(int x) {
        // 만약 parent[x]가 x 자신이라면, x가 루트(대표)라는 뜻
        if (parent[x] == x) {
            return x;
        }
        
        // 아니라면 부모를 따라 올라가면서 루트 찾기
        // 동시에 경로 압축: 바로 루트에 연결되도록 parent[x] 업데이트
        parent[x] = find(parent[x]);
        
        return parent[x];
    }

    // unite 함수: x와 y를 같은 그룹으로 합침
    void unite(int x, int y) {
        // 먼저 x와 y의 루트(대표)를 각각 찾음
        int rootX = find(x);
        int rootY = find(y);
        
        // 이미 같은 그룹이면 아무것도 안 함
        if (rootX == rootY) {
            return;
        }
        
        // 다르면 한 쪽 루트를 다른 쪽 루트의 자식으로 만듦
        // 여기선 단순히 rootX의 부모를 rootY로 설정
        parent[rootX] = rootY;
    }

// --------
// Union find 문제.. 내가생각한 backtracking, dfs, sort 로는 .. 시간초과로 안풀리는듯?
// --------
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        
        // 1. parent 배열 초기화: 처음엔 모두 자기 자신을 부모로
        // 예: parent = [0, 1, 2, 3, ...]
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        // 2. 모든 swap 가능한 쌍에 대해 unite 호출
        // 예: pairs = [[0,3], [1,2]] 이면
        // unite(0,3) → 0과 3이 같은 그룹
        // unite(1,2) → 1과 2가 같은 그룹
        for (const auto& p : pairs) {
            unite(p[0], p[1]);
        }
        
        // 3. 이제 같은 그룹에 속한 인덱스들을 모아야 함
        // map<루트, 그 루트에 속한 인덱스들의 리스트>
        map<int, vector<int>> groups;
        
        for (int i = 0; i < n; ++i) {
            int root = find(i);        // i의 루트 찾기
            groups[root].push_back(i); // 그 루트의 그룹에 i 추가
        }
        
        // 결과 문자열 (원본 복사해서 수정할 거임)
        string result = s;
        
        // 4. 각 그룹별로 처리
        for (auto& entry : groups) {
            // entry.first  → 루트 (그룹 대표)
            // entry.second → 이 그룹에 속한 모든 인덱스들 (vector<int>& indices)
            vector<int>& indices = entry.second;
            
            // (1) 인덱스들을 오름차순 정렬 → 작은 위치부터 채우기 위해
            sort(indices.begin(), indices.end());
            
            // (2) 이 인덱스들에 있던 문자들을 모아서 vector<char>에 저장
            vector<char> chars;
            for (int idx : indices) {
                chars.push_back(s[idx]);  // 원본 문자열에서 해당 위치 문자 가져옴
            }
            
            // (3) 문자들도 오름차순 정렬 → 가장 작은 문자부터 사용
            sort(chars.begin(), chars.end());
            
            // (4) 정렬된 인덱스 위치에 정렬된 문자들을 차례대로 배치
            // 예: indices = [0, 3], chars = ['b', 'd']
            // → result[0] = 'b', result[3] = 'd'
            for (size_t i = 0; i < indices.size(); ++i) {
                result[indices[i]] = chars[i];
            }
        }
        
        return result;
    }
};