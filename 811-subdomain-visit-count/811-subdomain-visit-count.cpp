class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        unordered_map<string, int> m; //k : domain, v : count

        for (const auto& word : cpdomains) {
            
            int i    = word.find (" "); 
            int n    = stoi (word.substr (0, i)); //횟수 파싱
            
            string s = word.substr (i+1, word.size ()-i-1); //도메인 파싱

            for (int i = s.size ()-1; i >= 0; i--) { //sub도메인 파싱해서 hash_map 넣기
                
                if (s[i] == '.')//점단위
                    m[s.substr (i+1, s.size ()-i-1)] += n; 
                else if (i == 0)//마지막 처리
                    m[s.substr (i,   s.size ()-i)  ] += n;
            }
        }

        vector<string> v;
        for (const auto& e : m) 
            v.push_back (to_string (e.second) + " " + e.first);
        return v;
        
    }
};