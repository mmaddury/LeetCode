class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        // Trivial cases
        if( s.size() == 0 && t.size() == 0 )
            return true;
        if( s.size() == 0 )
            return true;
        if( t.size() == 0 )
            return false;
        
    
        // Start at the beginning of s & t
        int sIdx = 0;
        int tIdx = 0;
        
        while( tIdx < t.size() ) {
            
            if( t[tIdx] == s[sIdx] ) {
                sIdx++;
            }
            
            if( sIdx == s.size() )
                return true;
            
            tIdx++;
                
        }
        
        return false;
    }
};