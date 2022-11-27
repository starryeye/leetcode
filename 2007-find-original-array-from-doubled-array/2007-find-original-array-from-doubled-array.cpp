class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        //배열이 홀수 갯수면 답이 없다.
        if(changed.size() % 2 == 1)
            return {};
        
        vector<int> answer;
        
        unordered_map<int, int> um;
        
        for(auto c : changed) {
            um[c]++;
        }
        
        //내림차순 정렬
        sort(changed.begin(), changed.end(), greater());
        
        for(int i = 0; i < changed.size(); i++) {
            
            if(um[changed[i]] <= 0)
                continue;
            
            //큰수 부터 보는데 홀수면 답이 없다.
            if(changed[i] % 2 == 1)
                return {};
            
            um[changed[i]]--;
            
            if(um.find(changed[i] / 2) != um.end()) {
                
                um[changed[i] / 2]--;
                answer.push_back(changed[i] / 2);
            }else {
                return {};
            }
        }
        
        return answer;
    }
};