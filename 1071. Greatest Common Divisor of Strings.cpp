class Solution {
public:
    
    bool
    stringDivide( const string& s, const string& d ) {
        if( (s.size() % d.size()) != 0 ) {
            return false;
        }
        for( int i=0; i<s.size(); i += d.size() ) {
            if( s.substr(i, d.size()) == d ) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    
    
    string 
    gcdOfStrings(string str1, string str2) {

        // set up str2 as the smaller string;
        if( str2.size() > str1.size() ) {
            swap(str1, str2);
        }
        string r = "";
        for( int i=0; i<str2.size(); i++ ) {
            if( str2.size() % (i+1) ) {
                // Current size must divide the size of str2
                continue;
            }
            string d = str2.substr(0, i+1);
            if( stringDivide( str1, d ) && stringDivide( str2, d ) ) {
                r = d;
            }
        }
        
        return r;
    }
};

