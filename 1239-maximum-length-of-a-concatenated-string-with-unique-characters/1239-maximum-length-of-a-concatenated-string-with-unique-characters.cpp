class Solution {
public:
    
    int solv(vector<string>& arr, string str, int index) {
        

	    //유니크 검사용
        unordered_set<char> us(str.begin(), str.end());
        
        //중복이라면.. 여기서 걸린다.
        if (us.size() != ((int)str.length())) 
            return 0;
        
        //all 유니크이므로 갯수 비교 준비
        int ret = str.length(); 
        
        for (int i = index; i < arr.size(); i++)
            ret = max(ret, solv(arr, str+arr[i], i+1));

        return ret;
    }
    
    int maxLength(vector<string>& arr) {
        
        return solv(arr, "", 0);
    }
    
};