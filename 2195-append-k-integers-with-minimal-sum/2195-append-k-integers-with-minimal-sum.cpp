class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        // 1 부터 k 까지의 숫자 합을 answer에 할당해 놓는다..
        long long answer = (static_cast<long long>(k) * static_cast<long long>(k + 1)) / 2;

        unordered_set<int> us(nums.begin(), nums.end());
        nums.clear();
        
        for(auto& u : us)
            nums.push_back(u);

        sort(nums.begin(), nums.end());
        
        
        for(int i = 0; i < nums.size(); i++){
            
            
            //k 보다 작은 숫자가 nums에 존재 할 경우엔 answer에서 nums[i]를 빼줘야한다.
            //빼줌과 동시에 answer에는 k + 1만큼 더해준다.
            if(nums[i] <= k){
                answer -= nums[i];
                answer += k + 1;
                k++;
            }
            else
                break;
        }
        return answer;
    }
    
    /*
    //time limit...
    long long minimalKSum(vector<int>& nums, int k) {
        
        int count = 0; //빠진 것 누적 갯수
        int seq = 1; //빠진 것 찾기 용
        int index = 0; //nums index
        long long answer = 0;
        
        
        unordered_set<int> us(nums.begin(), nums.end());
        nums.clear();
        
        for(auto& u : us)
            nums.push_back(u);
        
        sort(nums.begin(), nums.end());
        
        int prev = 0;
        
        while(count < k && index < nums.size()) {
            
            if(nums[index] != seq) {
                answer += seq++;
                count++;
            }else {
                index++;
                seq++;
            }
            
            
            
        }
        
        while(count < k) {
            answer += seq++;
            count++;
        }
        
        return answer;
    }
    */
    /*
    //time limit
    long long minimalKSum(vector<int>& nums, int k) {
        unordered_set<int> us;
        
        int maxNum = 0;
        
        for(auto n : nums) {
            us.insert(n);
            maxNum = max(maxNum, n);
        }
        
        int count = 0;
        long long sum = 0;
        
        for(int i = 1; i <= maxNum; i++) {
            
            if(count == k)
                return sum;
            
            if(us.find(i) != us.end())
                continue;
            
            count++;
            sum += i;
        }
        
        while(count < k) {
            
            sum += ++maxNum;
            count++;
        }
        
        return sum;
    }
    */
};