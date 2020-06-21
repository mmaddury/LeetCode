class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        //
        // Greedy approach
        // 
		// Work backwards. 
        // Pick the final step as min of cost[size()-1]
        // & cost[size()-2]
        // Final cost = cost[final_step] + min(cost[f-1],
        // cost[f-2] and so on

        /*
        int fs = ( cost[cost.size()-1] < cost[cost.size()-2] ? 
                   cost.size()-1 : cost.size()-2 );
        int totalCost = cost[fs];
        int i = fs;
        
        while (i >= 2 ) {
            if( cost[i-1] < cost[i-2] ) 
                i = i-1;
            else
                i = i-2;
            totalCost += cost[i];
        }
        
        return totalCost;
        */
        
        //
        // Work forwards
        //
        
        
        //
        // Dynamic Programming
        //
        // Need to cover all cases
        //  Use prefix sum and keep track of costs for both step selections
        //  by taking min at each point
        //
        
        // Pad cost with a dummy step w/ cost 0
        cost.push_back(0);
        
        // Store the path costs
        vector<int> pathCost;
        pathCost.push_back(cost[0]);
        pathCost.push_back(cost[1]);
        
        for(int i=2; i<cost.size(); i++ ) {
            pathCost.push_back(cost[i] + min(pathCost[i-1], pathCost[i-2]) );
        }
        
        return pathCost.back();
        
    }
};


