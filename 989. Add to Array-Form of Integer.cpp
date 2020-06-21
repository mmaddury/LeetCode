class Solution {
public:
    vector<int> 
    addToArrayForm(vector<int>& A, int K) {

        // Convert K to vector B
        vector<int> B;
        while( K ) {
            B.insert(B.begin(), K%10);
            K = K/10;
        }
        
        
        // Line up the vector A & B
        int a = A.size();
        int b = B.size();
        if( a>b ) {
            for( int i=0; i<(a-b); i++ ) {
                B.insert(B.begin(), 0);
                cout << i << endl;
            }
        }
        if( b>a ) {
            for( int i=0; i<(b-a); i++ ) {
                A.insert(A.begin(), 0);
            }
        }
        /*
        for( auto const& a : A ) {
            cout << a << " ";
        }
        cout << endl;
        for( auto const& b : B ) {
            cout << b << " ";
        }
        cout << endl;
        */
        
        // Reverse iteration and add
        vector<int> C(A.size(),0);
        int sum = 0;
        int carry = 0;
        for( int i=A.size()-1; i>=0; i-- ) {
            sum = A[i] + B[i] + carry;
            C[i] = sum % 10;
            carry = sum / 10;
        }
        if( carry ) {
            C.insert(C.begin(), 1);
        }
        
        return C;
    }
};