class MinStack {
    
private:
    vector<pair<int, int>> s; //{val, min}
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(s.empty()) {
            s.push_back({val, val});
            return;
        }
            
        
        if(val < s.back().second) {
            s.push_back({val, val});
            return;
        }
            
        s.push_back({val, s.back().second});
    }
    
    void pop() {
        
        s.pop_back();
    }
    
    int top() {
        
        return s.back().first;
    }
    
    int getMin() {
        
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */