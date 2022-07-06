class Solution {
public:
    
    //https://leetcode.com/problems/top-k-frequent-elements/discuss/81676/C%2B%2B-O(nlogk)-and-O(n)-solutions
    //min-heap O(nlogk), bucket sort O(n)
    
    
    //static 해줘야함..
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        
        return a.second > b.second;
    }
    
    //vector pair의 second 정렬, unordered_map의 keyToIndex
    //조금 다듬으면 bucket sort 가능
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> keyToIndex;
        
        vector<pair<int, int>> keyToCount;
        vector<int> answer;
        
        //O(n)
        for(auto num : nums) {
            
            
            if(keyToIndex.find(num) == keyToIndex.end()) {
                keyToCount.push_back({num, 1});
                keyToIndex[num] = keyToCount.size() - 1;
            } else {
                int index = keyToIndex[num];
                
                keyToCount[index].second++;
            }
        }
        
        //O(nlogn)
        sort(keyToCount.begin(), keyToCount.end(), cmp);
        
        for(int i=0; i<k; i++) {
            answer.push_back(keyToCount[i].first);
        }
        
        return answer;
    }
};