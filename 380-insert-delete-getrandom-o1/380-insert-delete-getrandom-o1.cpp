class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(um.find(val) == um.end()) {
            v.push_back(val);
            um[val] = v.size()-1;
        } else {
            return false;
        }
        
        return true;
    }
    
    bool remove(int val) {
        
        if(um.find(val) != um.end()) {
            
            int i = um[val];
            
            //pop_back을 위한.. 바꾸기
            v[i] = v[v.size()-1]; //vector, 맨 뒤에 것을.. 삭제할거에 덮어쓴다.(맨뒤에것을 살리기위함..)
            um[v[i]] = i; // 맨 뒤의 값의 인덱스를 i로 업데이트해준다.
            
            
            //삭제
            v.pop_back();
            um.erase(val);

        } else {
            return false;
        }
        
        return true;
    }
    
    int getRandom() {
        
        //unordered_set으로 .. 반복자를 호출했을때.. 랜덤한 값이 안나온다.
        //return *(us.begin());
        
        return v[rand()%v.size()];
    }
    
    //key(val), index
    unordered_map<int, int> um;
    
    //index, key(val)
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */