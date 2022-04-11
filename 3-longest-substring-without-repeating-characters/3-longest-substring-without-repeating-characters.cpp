//뭐가 문제인지 모르겠다
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)
            return 0;
        set<char> st; //check용
        int maxsize=0; //답
        int i=0,j=0; //i는 진행중인 최초 index를 저장, j는 진행중인 문자열 가장끝 index 저장
        while(j<n) //끝 index가 마지막 문자까지 갈때까지 순회
        {
            if(st.count(s[j])==0) //check용에 존재하지 않는다.
            {
                st.insert(s[j]); //check용에 저장
                maxsize=max(maxsize,(int)st.size()); //답 갱신
                j++; //끝 index이동
            }
            else //check용에 존재한다..
            {
                st.erase(s[i]); //중복되는 문자가 없어질때까지 삭제
                i++; //시작index 이동
            }
        }
        return maxsize;
    }
};

/*
//뭐가 문제인지 모르겠다
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int N = s.size();
        
        //예외처리
        if(!N)
            return 0;
        
        int ans = 1;
        
        
        //dp, 연속된 문자열 길이
        vector<int> dp(N, 0);
        //현재 연속된 문자열에 해당 문자가 존재하는지 check용, int는 해당 문자의 index를 가리킴
        unordered_map<char, int> um;
        
        //초기화
        um[s[0]] = 0;
        int minIndex = 0; //현재 갱신중인 dp는 minIndex부터 시작되었다.
        dp[0] = 1;
        
        for(int i =1; i<s.size(); i++)
        {
            if(um[s[i]]) // 현재 문자가 check용에 이미있는경우
            {
                
                //어디까지 날려야함?
                int tmpIndex = um[s[i]] + 1;
                
                //시작 문자부터 기존에 있던 문자(현재 문자와 중복된 문자)까지의 문자들을 날려줘야한다.
                for(int j = minIndex; j< tmpIndex; j++)
                {
                    um.erase(s[j]);
                }
                
                //현재 문자 um에 넣고, indexing 해주고
                um[s[i]] = i;
                //시작 문자 index 갱신
                minIndex = tmpIndex;
                
                dp[i] = tmpIndex + i + 1;
                
            }
            else // 현재 문자가 check용에 없는경우
            {
                um[s[i]] = i; //check용에 현재문자 넣음
                dp[i] = dp[i-1] + 1; //dp는 이전dp에서 +1 하여 현재 dp에 넣음
                
                
                
            }
            
            ans = max(ans, dp[i]); //max값 갱신
            

        }
        
        return ans;
    }
};
*/