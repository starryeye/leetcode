class HitCounter {
private:
    vector<int> timestamps;
    mutex mtx;

public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        lock_guard<mutex> lock(mtx);
        timestamps.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        lock_guard<mutex> lock(mtx);
        
        auto current_iter = upper_bound(timestamps.begin(), timestamps.end(), timestamp);
        auto previous_iter = upper_bound(timestamps.begin(), timestamps.end(), timestamp - 60 * 5);

        return current_iter - previous_iter;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */