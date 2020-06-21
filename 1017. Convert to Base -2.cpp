class Solution {
public:
    string 
    baseNeg2(int N) {
    
        if( N == 0 ) {
            return "0";
        }
        
        string rval="";
        
        while( N!=0 ) {
            int q = N/(-2);
            int r = N%(-2);
            
            // Key step is to add one to quotient when remainder is 
            // less that 0. For math details, refer to 
            // https://en.wikipedia.org/wiki/Negative_base
            
            if( r < 0 ) 
                N = q+1;
            else
                N = q;
            
        
            rval = to_string(r!=0) + rval;
            
        }
    
        return rval;
        
    }
};