class Solution {
public:
        
    static bool
    mySort( const vector<int>& A, const vector<int>& B ) {
          return A[1] - A[0] > B[1] - B[0]; 
    }
    
    
    void
    showVec( const vector<vector<int>>& v ) {
        for( auto const& i : v ) {
            for( auto const& j : i )
                cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
        

    int 
    twoCitySchedCost(vector<vector<int>>& costs) {
    
        //
        // Use greedy approach based on difference of cost per person
        // 1. Identify the difference between the cost to cities per person 
        // 2. Sort this in descending order. 
        //      a. Larger +ve diff implies that much better to go to city A
        //      b. Larger -ve diff implies that much better to go to city B
        // 3. The first N/2 should go to city A 
        // 4. The second N/2 should go to city B
        //
        
        
        //showVec(costs);
        sort(costs.begin(), costs.end(), mySort );
        //showVec(costs);
        
        int N = costs.size();
        
        int mCost = 0;
        for( int i=0; i<N/2; i++ )
            mCost += costs[i][0];
        for( int i=N/2; i<N; i++ )
            mCost += costs[i][1];
        
        return mCost;
        
    }
};