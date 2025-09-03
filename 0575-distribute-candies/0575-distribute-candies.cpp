class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        int candySize = candyType.size();
        unordered_set<int> type;

        for (int i = 0; i < candySize; i++) {
            type.insert(candyType[i]);
        }


        return min(candySize / 2, (int)type.size());
    }
};