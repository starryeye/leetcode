class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        //start index 만 찾으면 된다.
        
        
        
        int total_cost=0;
        int total_fuel=0;
        
        for(int i = 0; i < cost.size(); i++) {
            total_cost+=cost[i];
            total_fuel+=gas[i];
        }
        
        // If the total fuel is lesser than the cost then definitely we can't cover the whole cicular tour.
        if(total_fuel<total_cost) {
            return -1;
        }
        
        // else ) If the total fuel is sufficient enough to cover the circular tour then definitely an answer exists
        
        int curr_fuel=0;
        int start=0;
        
        for(int i = 0;i < cost.size(); i++) {
            // If at any point our balance/ current fuel is negative that means 
            // we can't come to the i'th petrol pump from the previous pump beacuse our fuel won't allow us to cover such distance. 
            // So we'll make the i'th pump as the start point ans proceed. 
            // Simultaneously we'll make the current fuel to be 0 as we're starting freshly.
            if(curr_fuel < 0) {
                start=i;
                curr_fuel=0;
            }
            // at any station we'll fill petrol and pay the cost to go to the next station . so current fuel would be the following.
            curr_fuel += gas[i] - cost[i];
        }
        
        return start;
    }
};