class Solution {
public:
    
    //discuss 참고함..
    //https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC%2B%2BPython-Let-Chopper-Help-Explain
    
    //북쪽, 동쪽, 남쪽, 서쪽 순
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    //instructions를 수행하고 마지막 상태에서 그대로 instructions를 반복 수행하는 형식이다.
    //circle이 하나만 만들어지면 된다.
    bool isRobotBounded(string instructions) {
        int y = 0;
        int x = 0;
        
        int i = 0;
        
        for(auto s : instructions) {
            if(s == 'R')
                i = (i + 1) % 4;
            else if(s == 'L')
                i = (i + 3) % 4;
            else {// s == 'G'
                y = y + dy[i];
                x = x + dx[i];
            }
        }
        
        if(x == 0 && y == 0) {
            return true; //(0,0)으로 돌아오면 이미 circle 형태이다..
        }else {
            //마지막 상태가 북쪽이 아니라면.. 계속 반복하다 보면 
            //(0,0) 좌표를 포함한 circle이 만들어지게 되어있다.
            if(i > 0)
                return true;
        }
        
        return false;
    }
};