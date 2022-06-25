class Solution {
public:
     vector<vector<int>> combine(int n, int k) {
         
         vector<vector<int>> answer;
         
         //[1,n] 배열
         vector<int> v;
        
         for(int i = 1; i <= n; i++) {
             v.push_back(i);
         }
        
         //0과 1이 담긴 뽑기용 vector, 1이면 뽑고.. 0이면 안뽑는것
         vector<int> r;
         
         //k개의 1
         for(int i = 0; i < k; i++) {
             r.push_back(1);
         }
         //n - k개의 0
         for(int i = 0; i < n-k; i++) {
             r.push_back(0);
         }
         
         sort(r.begin(), r.end());
        
         do{
             vector<int> temp;
             for(int i=0; i<r.size(); i++) {
                 if(r[i] == 1) {
                     temp.push_back(v[i]);
                 }
             }
             answer.push_back(temp);           
            
         }while(next_permutation(r.begin(), r.end()));        
        
         return answer;
    }
    /*
    //[[1,2],[1,3],[1,4],[2,1],[2,3],[2,4],[3,1],[3,2],[3,4],[4,1],[4,2],[4,3]]
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> v;
        
        for(int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        
        set<vector<int>> us;
        
        do{
            vector<int> temp;
            temp.push_back(v[0]);
            temp.push_back(v[1]);
            us.insert(temp);
        }while(next_permutation(v.begin(), v.end()));
        
        
        vector<vector<int>> answer;
        
        for(auto u : us) {
            answer.push_back(u);
        }
        
        return answer;
    }
    */
};