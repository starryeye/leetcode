class Solution {
public:
    
    //discuss에 deque를 활용하면 더욱 효율적인 시간복잡도로 풀수있다.
    //아래 풀이는 O(nlogk)
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
        // create a priority queue (Max Heap) of pair of int
        // first of the pair is the element of the array
        // and second is the index
        priority_queue<pair<int,int>> p;
        
        // create a vector to store the result
        vector<int>res;
        
        // add all the elements in the first window to the PQ
        for(int i = 0; i < k; i++)
            p.push({arr[i],i});
        
        // add the max element of first window to the res vector
        res.push_back(p.top().first);
        
        // start iteration from the second window
        for(int i = k; i < arr.size(); i++) {
            
            // add the element into the PQ
            p.push({arr[i],i});
            
            // top의 index만 보면서 sliding window 범위를 벗어나면 없애준다.
            // 따라서, 순간적으로 pq에 k보다 많은 elements가 존재 할 수 있다.
            // remove all the elments which are not in the current window
            // current window is from [i-k+1 , i]
            while(!(p.top().second > i-k))
                p.pop();
            
            // add the max element in the PQ to the res
            res.push_back(p.top().first);
        }
        
        // return the result
        return res;
    }
};