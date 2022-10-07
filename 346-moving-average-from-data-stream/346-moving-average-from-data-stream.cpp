class MovingAverage {
public:
    MovingAverage(int size) {
        totalSize = static_cast<double>(size);
        currentSize = 0.0;
        sum = 0.0;
    }
    
    double next(int val) {
        
        double ret = 0;
        
        if(totalSize == currentSize) {
            sum -= arr.front();
            arr.pop();
            
        }else {
            currentSize++;
        }
        
        arr.push(static_cast<double>(val));
        sum += static_cast<double>(val);
        
        return sum / currentSize;
    }
    
    queue<double> arr;
    double sum;
    double totalSize;
    double currentSize;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */