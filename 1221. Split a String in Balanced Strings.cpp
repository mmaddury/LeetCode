class Solution {
public:
    int 
    balancedStringSplit(string s) {
    
        // Not sure why this need greedy approach
        // Could be because and each time we reach a 
        // match, we increment our count
        
        int splits = 0;
        int bCount = 0;     // balanced when count = 0
        for( auto const& c : s ) {
            if( c == 'L')
                bCount++;
            else
                bCount--;
            if( bCount == 0 )
                splits++;
        }
        
        return splits;

    }
};