class Solution {
public:
    
    /*
    int
    findLeastLarger( const vector<int>& A, int b ) {
        
        int rIdx = -1;
        
        for( int i=0; i<A.size(); i++ ) {
            if( A[i] > b ) {
                rIdx = i;
                break;
            }
        }
        
        return (rIdx == -1) ? 0 : rIdx;
        
    }
    */
    
    void
    showVec( const vector<int>& v, const string& s="" ) {
        if( s != "" )
            cout << s << " ";
        for( auto const& i : v )
            cout << i << " ";
        cout << endl;
    }
    
    int
    findLeastLarger( const vector<int>& A, int b ) {
        
        int l=0;
        int r=A.size()-1;
        int rIdx = -1;
        
        /*
        cout << "------------------------" << endl;
        showVec(A, "A");
        cout << "b " << b << endl;
        */
        
        while( l < r ) {
            int m = (l+r)/2;
            //cout << "l,r,m " << l << "," << r << "," << m << endl;
            //cout << "A[m] " << A[m] << endl;
            if( A[m] > b )
                r = m;
            else
                l = m+1;
            //cout << "l,r,m " << l << "," << r << "," << m << endl;
            if( (l == r) && (A[r] > b) )
                rIdx = r;
        }

        //cout << "rIdx " << rIdx << endl;
        return (rIdx == -1) ? 0 : rIdx;

    }
    
    
    vector<int> 
    advantageCount(vector<int>& A, vector<int>& B) {

        vector<int> res;
        sort(A.begin(), A.end());
        
        for( int i=0; i<B.size(); i++ ) {
            int j = findLeastLarger( A, B[i] );
            res.push_back(A[j]);
            A.erase(A.begin()+j);
            //showVec(res, "res");
        }
        
        return res;
        
    }
};