class StockPrice {
    //map으로 풀려고 했지만 gg..
    //map은 총 2개로 풀려고 했고.. 
    //하나는 (k:time, v:price), 
    //다른하나는 가격 정렬용 (k:price, v:timelist)
    //근데 너무 힘들더라..
    
    //discuss에서는 multiset으로.. 중복이 허용되는 set을 사용했다.
    //아래는 그 풀이..
    //each function t : O(logn), s : O(n)
public:
    
    multiset<int> pricelist;
    map<int, int> timePrice;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        
        if(timePrice.find(timestamp) != timePrice.end()) {
            pricelist.erase(pricelist.find(timePrice[timestamp])); //원소 한개만 삭제
            //참고, multiset에서 erase(element) 할 경우, 모든 원소가 삭제됨.
        }
        
        //원래 있든 없든
        timePrice[timestamp] = price;
        pricelist.insert(price);
    }
    
    int current() {
        return timePrice.rbegin() -> second; //원소가 k,v 이므로 "->"
    }
    
    int maximum() {
        return *pricelist.rbegin(); //원소가 하나이므로 "*"
    }
    
    int minimum() {
        return *pricelist.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */