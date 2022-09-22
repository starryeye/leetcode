class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        
        vector<vector<string>> answer(searchWord.size());
        
        for(int i = 0; i < searchWord.size(); i++) {
            
            string s = searchWord.substr(0, i+1);
            
            int count = 0;
            for(int j = 0; j < products.size(); j++) {
                if(products[j].substr(0, s.size()) == s) {
                    answer[i].push_back(products[j]);
                    count++;
                }
                
                if(count == 3)
                    break;
            }
        }
        
        return answer;
    }
};