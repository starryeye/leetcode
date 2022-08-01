class Solution {
public:
    //밑에 시간 초과 나는 완전탐색과 비교 잘 해야함.. 
    //backtracking의 핵심은 유망하지 않으면 그 즉시, 바로 부모노드로 되돌아가는 것이다. 다음 자식노드를 순회하지 않는다.
    // 참고가 될지 모르겠지만.. 해당 문제 git note에 Sum과 recur 함수의 초반부에 바로 r, ans에 대한 출력물을 기록해놓겠다..
    // input : (2,3,6,7), output : (2,2,3), (7)
    void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& r, int i) {
        
        if(target == 0)
        {
            res.push_back(r);
            return;
        }
        
        //i는 candidates의 인덱스이다.
        //i가 0부터 시작해서 0index만 사용한 경우부터 쭈우욱해서 최종적으로 최종 index만 사용한 경우까지
        //순회한다..
        //중복있고..순서없는 조합
        while(i <  candidates.size() && target - candidates[i] >= 0)
        {
            // Till every element in the array starting
            r.push_back(candidates[i]);
            
            // recur for next numbers
            Sum(candidates,target - candidates[i],res,r,i);
            ++i;
            
            // Remove number from vector (backtracking)
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); // sort candidates array
        
        // remove duplicates, 필요 없음, 이미 unique로 주어지는듯..
        //candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        
        vector<int> r;
        vector<vector<int>> res;
        
        Sum(candidates,target,res,r,0);
        
        return res;
    }
    
    
    /*
    //time limit...
    void recur(set<vector<int>>& answer, vector<int> ans, vector<int> candidates, int target) {
        
        if(accumulate(ans.begin(), ans.end(), 0) == target) {
            sort(ans.begin(), ans.end());
            answer.insert(ans);
        }else if(accumulate(ans.begin(), ans.end(), 0) > target) {
            return;
        }
        
        for(auto c : candidates) {
            ans.push_back(c);
            recur(answer, ans, candidates, target);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        set<vector<int>> answer;
        vector<int> ans;
        int sum = 0;
        
        recur(answer, ans, candidates, target);
        
        vector<vector<int>> ret(answer.begin(), answer.end());
        
        return ret;
    }
    */
};