class Solution {
public:
    
    bool 
    isValid(string s) {
        
        // Use a stack to maintain the characters
        vector<char> stack;
        
        for( auto const& c : s ) {
            if( c == '{' || c == '(' || c == '[' ) {
                stack.push_back(c);
            } else if( ( c == '}' && stack.size() && stack.back() == '{' ) ||
                       ( c == ')' && stack.size() && stack.back() == '(' ) ||
                       ( c == ']' && stack.size() && stack.back() == '[' ) ) {
                stack.pop_back();
            } else {
                return false;
            }
        }
        
        if( stack.size() )
            return false;
        
        return true;
        
    }
        
};