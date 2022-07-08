class Solution {
public:
    //count : IP는 count 총 4개, 점(.)으로 구분되는 영역
    //start : s의 index, 지금까지 s의 몇번째 index까지 진행되었고.. 몇 index부터 보면 되는지..
    //dfs는 count 개수 만큼 호출된다.
    void dfs(string s, int start, int count, string makeIp, vector<string>& answer) {
        if(start == s.size() && count == 4) {
            makeIp.erase(makeIp.end() - 1);
            answer.push_back(makeIp);
            return;
        }
        
        if(s.size() - start > (4 - count) * 3) // 남은 count 내에 .. 남은 s가 다 못들어감(넘침)
            return;
        if(s.size() - start < (4 - count)) // 남은 s가 남은 count 내에 들어가기엔 부족함
            return;
        
        int cur = 0;
        for(int i = start; i < start+3; i++) { //for문은 보기시작하면되는 s index(start) 부터 최대 3개를 볼 수 있다.
            cur = cur * 10 + (s[i] - '0'); //cur : 하나의 영역(같은 count)에서 만들 수 있는 .. ip
            
            if(cur <= 255) {//cur은 최대 255까지 이다.
                makeIp += s[i];//만들어진 cur을 하나의 영역으로 fix하고 다음 dfs를 호출한다.
                dfs(s, i+1, count+1, makeIp + '.', answer);
            }
            if(cur == 0)
                break;
        }
    }
    
    //backtracking .. solution은?
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        
        string makeIp;
        
        dfs(s, 0, 0, makeIp, answer);
        
        return answer;
    }
};