//380 처럼 key로 배열류 자료구조의 index(iterator)를 저장하는 unordered_map 사용
class LRUCache {
public:
    LRUCache(int capacity) : size(capacity) {}
    
    int get(int key) {
        
        //없음
        if (kv.count(key) == 0) 
            return -1;
        
        //있음
        updateLRU(key);
        return kv[key];
    }
    
    void updateLRU(int key) {
        
        //있으면 기존 사용 순위에서 삭제
        if (kv.count(key)) 
            lru.erase(mp[key]);
        
        //가장 최근 사용으로.. front에 넣음
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    
    void put(int key, int value) {
        
        //꽉 차있고.. 새로운 key가 들어가야한다.
        if (kv.size() == size && kv.count(key) == 0)
            evict();
        
        updateLRU(key);
        kv[key] = value;
    }
    
    void evict() {
        
        //순위가 가장 낮은 것 삭제
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
    
    int size;
    list<int> lru;                              // 사용순위, index가 작을 수록 최근에 사용
    unordered_map<int, list<int>::iterator> mp; // key -> iterator
    unordered_map<int, int> kv;                 // key -> value
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */