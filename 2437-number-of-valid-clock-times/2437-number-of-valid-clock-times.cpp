class Solution {
public:
    int countTime(string time) {
        
        int answer = 1;
        
        //분
        if(time[4] == '?') 
            answer = answer * 10;
        if(time[3] == '?') 
            answer = answer * 6;
        
        //시
        if(time[0] == '?' && time[1] == '?') 
            answer = answer * 24;
        else{
            if(time[1] == '?') { 
                if(time[0] == '2' ) 
                    answer = answer * 4;
                else 
                    answer = answer * 10;
            }
            
            if(time[0] == '?') {
                if(time[1] < '4') 
                    answer = answer * 3;
                else 
                    answer = answer * 2;
            }
        }
        
        return answer;
    }
};