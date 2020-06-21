class Solution {
public:
    
    bool 
    canConstruct(string s, int k) {
        
        // Not enough characters
        if( s.size() < k )
            return false;
        
        // Trivial case of single character palindrome
        if( s.size() == k )
            return true;
        
        // A palindrome is either "eeee_O_eeee" or "eeee_eeee"
        // where e are even occurence and O is an odd occurence
        // K palindrome imply that you can atmost K characters with
        // off occurences in the string
        
        // Count the occurence of each character, use the ASCII code
        // adjusted to handle the 26 lower case letters
        vector<int> count(26,0);
        for( auto const& c : s )
            count[c-'a']++;
        
        for( auto const& i : count ) {
            if( i%2 == 1 )
                k--;
            if( k < 0 )
                return false;
        }
        
        return true;
        
    }
};