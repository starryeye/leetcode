class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> us;
        
        for(auto email : emails) {
            
            string real;
            
            int i = 0;
            for( ; i < email.size(); i++) {
                if(email[i] == '.')
                    continue;
                if(email[i] == '@' || email[i] == '+')
                    break;
                
                real += email[i];
            }
            
            real += email.substr(email.find('@', i));
            //substr(시작위치, 길이)
            //-> 길이를 생략하면 시작위치에서 문자열 끝까지이다.
            //find(찾을것, 시작위치)
            //-> find의 두번째 파라미터는 해당 index부터 마지막 인덱스까지 찾아보라는 범위 지정이다.
            us.insert(real);
        }
        
        return us.size();
    }
};