class Logger {
public:
    unordered_map<string, int> um;
    
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        if(um.find(message) == um.end()) {
            um[message] = timestamp;
            return true;
        }
        
        if(um[message] + 10 > timestamp) {
            return false;
        }else {
            um[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */