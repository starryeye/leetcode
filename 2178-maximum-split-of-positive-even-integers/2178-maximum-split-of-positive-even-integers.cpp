class Solution {
public:
    /*
    //greedy라는데 이게 왜 되는지 모르겠음..
    //이게 최대 갯수를 가지는.. 집합이 어떻게 가능한지..
    //28 input 이면 {2,4,6,16} 이 아웃풋으로 나옴
    //answer에 8을 넣고 i가 10으로 변하면서 while문 빠져나오고.. 8 + 8로 16이 됨
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        //홀수 예외 처리
        if(finalSum % 2 == 1)
            return {};
        
        vector<long long> answer;
        
        long long i = 2;
        
        while(finalSum >= i) {
            answer.push_back(i);
            finalSum -= i;
            i += 2;
        }
        
        if(finalSum) {
            answer[answer.size() - 1] += finalSum;
        }
        
        return answer;
    }
    */
    //backtracking
    //직접 디버깅 돌려보고 recursion이 어떻게 이루어지는지 볼것..
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        //홀수 예외 처리
        if(finalSum % 2 == 1)
            return {};
        
        vector<long long> answer;
        
        function<bool(long, long)> dfs = [&](long i, long target) {
            
            if(target == 0)
                return true;
            
            if(target < i)
                return false;
            
            answer.push_back(i);
            
            if(dfs(i + 2, target - i)) //use i, false 리턴이면 pop_back으로 간다.
                return true;
            
            answer.pop_back();
            
            return dfs(i + 2, target); //skip i
        };
        
        dfs(2, finalSum);
        
        return answer;
    }
};