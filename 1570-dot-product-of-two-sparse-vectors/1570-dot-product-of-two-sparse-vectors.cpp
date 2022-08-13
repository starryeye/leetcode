class SparseVector {
public:
    
    vector<int> getVec() {
        return v;
    }
    
    SparseVector(vector<int> &nums) {
        copy(nums.begin(), nums.end(), back_inserter(v));
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        
        vector<int> input = vec.getVec();
        
        if(input.size() != v.size()) {
            return -1;
        }
        
        int answer = 0;
        
        for(int i = 0; i < v.size(); i++) {
            answer += v[i] * input[i];
        }
        
        return answer;
    }

private:
    vector<int> v;
    
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);