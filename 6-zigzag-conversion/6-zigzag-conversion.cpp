class Solution {
public:
    string convert(string s, int numRows) {
        
        //예시 기준 아래처럼 3칸 배열에 쌓이도록 구현
        //PAHN
        //APLSIIG
        //YIR
        
        if(numRows==1)
            return s;
    
        int y=0; //행의 index
        bool flag= true; //true : y가 양수로 간다. false : y가 음수로 간다. (행 변경 방향)
        vector<string> sArray(numRows, "");
        
    
        for(int i=0;i<s.length();i++)
        {
        
            sArray[y]+=s[i];
        
            //행의 index(y)에 따라 앞으로의 행 변경 방향을 잡는다 , 0이면 양수방향, 2라면 음수 방향
            if(y==0)
            {//0이라면 무조건 true 셋팅
                flag=true;
            }
            else if(y==numRows-1)
            {//3이라면 2인덱스 부터 뒤돈다
                flag=false;
            }
        
            //행 변경 방향에 따라 y의 변경이 달라진다.
            if(flag==true)
            {
                y++;
            }
            else
            {
                y--;
            }
        

        }

        string ret="";
    
        for(int i=0;i<numRows;i++)
        {
            ret+=sArray[i];
        }
    
        return ret;
        
    }
};