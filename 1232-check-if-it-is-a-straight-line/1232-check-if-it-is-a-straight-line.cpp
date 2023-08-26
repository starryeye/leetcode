class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int lineSize = coordinates.size();
        
        if (lineSize == 1) 
            return false;
        if (lineSize == 2) 
            return true;
        
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        
        int dx = coordinates[1][0] - x0;
        int dy = coordinates[1][1] - y0;
        
        for (int i = 1; i < lineSize; i++) {
            
            int cx = coordinates[i][0];
            int cy = coordinates[i][1];
            
            if (dx * (cy - y0) != dy * (cx - x0))
			    return false;
        }
        return true;
    }
};