class Solution {
public:
    
    /*
    void
    genCombinations( vector<vector<int>>& r, 
                     vector<int>& stack, 
                     vector<int>& v, 
                     int k, 
                     int index ) { 

        if( stack.size() == k ) {
            r.push_back(stack);
            return;
        }
        
        for( int i=index; i<v.size(); i++ ) {
            stack.push_back(v[i]);
            genCombinations( r, stack, v, k, i+1 );
            stack.pop_back();
        }
        
        return;
    }
    */
    
    
    void
    genCombinations( vector<vector<int>>& r, 
                     vector<int>& stack, 
                     vector<int>& v, 
                     int k, 
                     int index ) { 

        if( k == 0 ) {
            r.push_back(stack);
            return;
        }
        
        for( int i=index; i<v.size(); i++ ) {
            stack.push_back(v[i]);
            genCombinations( r, stack, v, k-1, i+1 );
            stack.pop_back();
        }
        
        return;
    }
    
    
    
    vector<vector<int>> 
    combine(int n, int k) {
    
        // Set up result vector
        vector<vector<int>> r;
        
        // Set up input vector
        vector<int> v(n,0);
        for( int i=0; i<n; i++ ) {
            v[i] = i+1;
        }
        
        // Use a stack for backtracking
        vector<int> stack;
        
        genCombinations(r, stack, v, k, 0);

        return r;
        
        
    }
};