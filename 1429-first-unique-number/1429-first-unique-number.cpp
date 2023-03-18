class FirstUnique {
    
private:
    queue<int> que;                     // To keep the order of elements maintained
    unordered_map<int, int> freq;      // To keep the frequency of each element
    
public:
    FirstUnique(vector<int>& nums) {
        
        freq.clear();
        
        while(!que.empty())
            que.pop();
        
        for (auto num: nums) {
            que.push(num);
            freq[num]++;
        }
    }
    
    //Time Complex : O(n)
    int showFirstUnique() {
        
        while(!que.empty() && freq[que.front()] > 1) {
            que.pop();
        }
        
        if(que.empty()) 
            return -1;
        else 
            return que.front();
    }
    
    void add(int value) {
        
        que.push(value);
        freq[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */