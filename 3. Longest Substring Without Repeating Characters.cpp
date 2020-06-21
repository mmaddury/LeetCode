class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,bool> m;
        string         r;
        int            rval=0;
        string         rs;
                
        for( int i=0; i<s.size(); i++ ) {
            if( m.find(s[i]) == m.end() ) {
                m[s[i]] = true;
                r += s[i];
            } else {
                // Save the size of the current max
                if( rval < r.size() ) {
                    rval = r.size();
                    rs = r;
                }
                // Find the portion of the current max to use
                // for the new max
                size_t pos = r.find(s[i]);
                if( pos != string::npos ) {
                    r.erase(0, pos+1);
                }
                // cout << "r = " << r << endl;
                r += s[i];
                // cout << "r = " << r << endl;
            }
        }
        
        rval = (rval > r.size()) ? rval : r.size();
        return rval; 
    }
};