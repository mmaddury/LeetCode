class Solution {
public:
    
    void
    showVec( const vector<int>& v, const string& s="") {
        if( s!="" )
            cout << s << " ";
        for( auto const& i : v )
            cout << i << " ";
        cout << endl;
    }
    
    void
    extractCol( vector<int>& r, const vector<vector<int>>& v, int k ) {
        for( int i=0; i<v.size(); i++ ) {
            vector<int> t = v[i];
            //cout << "i, k " << i << " " << k << " " << t[k] << endl;
            r.push_back(t[k]);
        }
    }
    
    int
    getNumOne( const vector<int>& v ) {
        int r = 0;
        for( auto const& i : v )
            r = (i == 1) ? r+1 : r;
        return r;
    }
    
    int 
    matrixScore(vector<vector<int>>& A) {
        
        
        //A = {{0,1,1},{1,1,1},{0,1,0}};
        
        int nr = A.size();
        int nc = A[0].size();

        // Apply greedy approach
        // 1. Col[0] contributes the most to all rows, flip all 
        //    zeros in col[0] by flipping corresponding rows
        // 2. Then check each column from [1]..[N-1] in order
        //    a. If a column has more than nr/2 zero, flip the col
        // 3. Can compute the sum without actually flipping the after
        //    step 1

        for( int i=0; i<nr; i++ ) {
            if( A[i][0] == 0 ) {
                for( int j=0; j<nc; j++ )
                    A[i][j] = !A[i][j];
            }
        }
        
        
        
        // This vector maintains the contribution of each columns 1
        vector<int> colTotal(nc,0);
        for( int i=0; i<nc; i++ ) {
            
            vector<int> t;
            extractCol(t, A, i);
            //showVec(t, to_string(i));
            
            int no = getNumOne( t );
            //cout << i << " " << no << " ";
            if( no < (nr-no) )
                no = nr - no;       // Number of ones, flipped or regular
            //cout << no << endl;
            colTotal[i] = no*(1 << (nc-1-i));
        }
        //showVec(colTotal, "colTotal");
        
        int score = 0;
        for( auto const& i : colTotal )
            score += i;
        
        return score;
    }
};