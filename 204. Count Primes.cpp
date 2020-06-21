class Solution {
public:
    
    void
    showVec( const vector<int>& v ) {
        for( auto const& i : v )
            cout << i << " ";
        cout << endl;
    }
    
    size_t
    getFirstZero( vector<int>& sieve ) {
        static size_t savedIdx;
        for( size_t i=savedIdx; i<sieve.size(); i++ ) {
            if( sieve[i] == 0 ) {
                savedIdx = i;
                return i;
            }
        }
        return sieve.size();
    }
    int savedIdx = 0;
    
  
    
    int 
    countPrimes(int n) {
    
        if( n == 0 || n == 1 ) 
            return 0;
        
     
        // Use Sieve of Erastothenes
        // -1 : not a prime
        //  0 : not yet evaluated
        // +1 : prime
        vector<int> sieve(n,0);
        
        // Set 0 & 1 to be not prime
        sieve[0] = -1;
        sieve[1] = -1;
        
        size_t idx = 0;
        while( idx < sieve.size() ) {
            
            idx = getFirstZero(sieve);
            //cout << idx << " ";
            if( idx < sieve.size() ) 
                sieve[idx] = 1;
            
            for( size_t j=2*idx; j<sieve.size(); j+=idx ) {
                sieve[j] = -1;
            }
        
            //showVec(sieve);
        }
        //cout << endl;
        
        showVec(sieve);
        int numPrimes = 0;
        for( size_t i=0; i< sieve.size(); i++ ) { 
            if( sieve[i] == 1 ) {
                cout << i << " ";
                numPrimes++;
            }
        }
        cout << endl;
     
        return numPrimes;
        
    }
    
};