class Solution {
public:
    
    int
    getIndex( int b ) {
        if( b == 5 )
            return 0;
        else if( b == 10 )
            return 1;
        else if( b == 20 )
            return 2;
        else
            return -1;
    }
    
    
    
    bool
    getChange( vector<int>& bank, int p ) {
        
        static vector<int> changeV{0, 5, 15};
        int change = changeV[p];
        
        if( change == 0 )
            return true;
        
        else if( change == 5 ) {
            if( bank[0] > 0 ) {
                bank[0]--;
                return true;
            }
        }
        
        // Implement greedy when selecting change for $20
        // Use $10 if available to save $5 for a future
        // customer
        else if( change == 15 ) {
            if( bank[1]>0 && bank[0] > 0) {
                bank[1]--;
                bank[0]--;
                return true;
            } else if( bank[0] >= 3 ) {
                bank[0] -= 3;
                return true;
            } else
                return false;
        }
        
        return false;
        
    }
    
    
    
    bool 
    lemonadeChange(vector<int>& bills) {
            
        // Maintain the bills available in bills
        // [0] : $5, [1] : $10, [2] : $20
        vector<int> bank(3,0);
        
        for( auto const& b : bills ) {
            int p = getIndex(b);
            if( getChange( bank, p ) == false )
                return false;
            bank[p]++;
        }
        
        return true;
        
    }
};