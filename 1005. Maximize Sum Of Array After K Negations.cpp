class Solution {
public:
    
    void
    showVec( const vector<int>& v, const string& s="" ) {
        if( s!="" )
            cout << s << " ";
        for( auto const& i : v )
            cout << i << " ";
        cout << endl;
    }
    
    int
    findMin( const vector<int>& A ) {
        
        int m = numeric_limits<int>::max();
        int mIdx = 0;
        int i = 0;
        for( i=0; i<A.size()-1; i++ ) {
            if( A[i] < m ) {
                m = A[i];
                mIdx = i;
            }
        }
        
        return mIdx;
        
    }
    
    
    
    int 
    largestSumAfterKNegations(vector<int>& A, int K) {
        
        //A = {-8, 3, -5, -3, -5, -2};
        //K = 6;
        
        //
        // Use greedy approach
        // If no negative numbers
        //   a. If zero available, pick zero only
        //   b. If no zero, pick the smalled positive number
        // If negative number
        //   a. Pick most negative number
        //
        
        // First sort the array
        sort(A.begin(), A.end());
        //showVec(A, "A");
        
        // No negative numbers - always pick index[0]
        if( A[0] >= 0 ) {
            int sum = accumulate(A.begin(), A.end(), 0);
            if( K%2 == 0 )
                return sum;
            else 
                return sum-2*A[0];
        } 
        
        // Have negative numbers, pick the first K numbers as long
        // as they are negative. 
        else {
            int i = 0;
            int j = 0;
            for( i=0; i<K; i++ ) {
                if( A[i] < 0 ) 
                    A[i] = -A[i];
                else {
                    j = findMin(A);
                    showVec(A);
                    cout << i << endl;
                    break;
                }
            }
            //showVec(A, "A");
            //cout << i << endl;
            // i has the remainder count
            int sum = accumulate(A.begin(), A.end(), 0);
            if( (K-i)%2 == 0 )
                return sum;
            else
                return sum-2*A[j];
        }
        
        
        return 0;
        
    }
};