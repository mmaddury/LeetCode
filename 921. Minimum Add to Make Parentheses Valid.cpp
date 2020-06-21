class Solution {
public:
    
    bool
    isBalanced( const char c1, const char c2 ) {
        if( c1 == '(' && c2 == ')' )
            return true;
        return false;
    }
    
    int 
    minAddToMakeValid(string S) {
               
        stack<char> st;
        
        for( auto const& c : S ) {
            
            if( st.empty() ) 
                st.push(c);
            else if( isBalanced( st.top(), c ) ) 
                st.pop();
            else 
                st.push(c);
                    
        }
        
        return st.size();
        
    }
};