class Solution {
public:
    int 
    findContentChildren(vector<int>& g, vector<int>& s) {
    
        //
        // Apply greedy method
        //
        // Sort greed and size vector, start at minimum of each
        // i is size counter, j is greed counter
        // If size[i] >= greed[j] 
        //   1. increase contect count
        //   2. increase i, j
        // Else
        //   1. increase i and try again
        //

        
        
        if( s.size() == 0 || g.size() == 0 )
            return 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0;
        int j = 0;
        int count = 0;
        while( ( i < s.size() ) && ( j < g.size() ) ) {
            if( s[i] >= g[j] ) {
                count++;
                i++;
                j++;
            } else {
                i++;
            }
        }             
                                                 
        
        return count;
        
    }
};