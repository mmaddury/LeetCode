class Solution {
public:
    
    void
    buildVector( vector<int>& v, string& s ) {
        while( s.size() ) {
            size_t delim = s.find('.');
            if( delim != string::npos ) {
                string t = s.substr(0, delim);
                v.push_back(stoi(t));
                s.erase(0,delim+1);
            } else {
                string t = s;
                v.push_back(stoi(t));
                s.clear();
            }
        }
    }
    
    void
    adjustVector( vector<int>& v1, vector<int>& v2 ) {
        int v1Size = v1.size();
        int v2Size = v2.size();
        
        if( v1Size > v2Size ) {
            for( int i=0; i<v1Size-v2Size; i++ )
                v2.push_back(0);
        } else {
            for( int i=0; i<v2Size-v1Size; i++ )
                v1.push_back(0);            
        }
    }
    
    void
    showVector( const vector<int>& v, const string& s="" ) {
        if( s != "" )
            cout << s << " ";
        for( auto const& i : v ) 
            cout << i << " ";
        cout << endl;
    }
    
    
    int 
    compareVersion(string version1, string version2) {
        
        vector<int> v1, v2;
        buildVector(v1, version1);
        buildVector(v2, version2);
        
        adjustVector(v1, v2);
        
        // showVector(v1, "v1");
        // showVector(v2, "v2");
        
        for( int i=0; i<v1.size(); i++ ) {
            if( v1[i] > v2[i] )
                return 1;
            else if( v1[i] < v2[i] )
                return -1;
        }
        
        return 0;
    }
};