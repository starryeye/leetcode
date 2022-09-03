class MyCalendar {
public:
    //참고..
    //lowerbound : 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
    //upperbound : 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        auto next = startend.lower_bound(start);
        
        if(next != startend.end() && next->first < end)
            return false;
        
        if(next != startend.begin() && (--next)->second > start)
            return false;
        
        startend[start] = end;
        
        return true;
            
    }
    
    map<int, int> startend;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */