class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> A;
        vector<int> B;
        
        unordered_map<char, int> S; //second : 당시의 a
        unordered_map<char, int> T; //second : 당시의 b
        
        int a = 0;
        int b = 0;
        
        for(int i = 0; i<s.size(); i++) {
            if(S.find(s[i]) == S.end()) {
                S[s[i]] = a;
                A.push_back(a++);
            }else {
                A.push_back(S[s[i]]);
            }
        
            if (T.find(t[i]) == T.end()) {
                T[t[i]] = b;
                B.push_back(b++);
            }else {
                B.push_back(T[t[i]]);
            }
        }
        
        if(A == B) {
            return true;
        }else {
            return false;
        }
    }
    
};