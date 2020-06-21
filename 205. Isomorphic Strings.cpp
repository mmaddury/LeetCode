class Solution {
public:
    void
    showVec( const vector<int>& v, const string& s="" ) {
        if( s != "" )
            cout << s << " : ";
        for( auto const& i : v )
            cout << i << " ";
        cout << endl;
    }
    
    
    bool 
    isIsomorphic(string s, string t) {
    
        if( s.size() != t.size() )
            return false;
        
        vector<int> sCount(26, 0);
        vector<int> tCount(26, 0);
        
        for( auto const& c : s )
            sCount[static_cast<size_t>(c-'a')]++;
        
        for( auto const& c : t )
            tCount[static_cast<size_t>(c-'a')]++;
        
        //showVec(sCount, "sCount");
        //showVec(tCount, "tCount");
        
        vector<int> sDist(s.size()+1,0);
        vector<int> tDist(t.size()+1,0);
        
        for( auto const& i : sCount ) 
            sDist[i]++;
        for( auto const& i : tCount )
            tDist[i]++;
        
        //showVec(sDist, "sDist");
        //showVec(tDist, "tDist");
        
        for( size_t i=1; i<sDist.size(); i++ ) {
            if( sDist[i] != tDist[i] )
                return false;
        }
        
       return true; 
        
    }
};