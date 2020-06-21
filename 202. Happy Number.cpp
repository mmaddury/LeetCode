class Solution {
public:
    
    int
    numDigits( int n ) {
        return static_cast<int>(ceil(log(static_cast<double>(n))));
    }
    
    
    int
    digitSqrSum( int n ) {
        
        int k = numDigits(n);
        int sqrSum = 0;
        
        //cout << n << " : ";
        for( int i=0; i<k; i++ ) {
            int digit = n % 10;
            n = n/10;
            sqrSum += digit * digit;
        }
        //cout << sqrSum << endl;
        return sqrSum;
    }
    
    
    
    bool 
    isHappy(int n) {
    
        if( n == 0 )
            return false;
        
        if( n == 1 )
            return true;
        
        // Use a map to track integers
        map<int, bool> nMap;
        bool happyNum = false;
        
        while( !happyNum ) {
            
            n = digitSqrSum(n);
        
            if( n == 1 )
                happyNum = true;
            
            if( nMap.find(n) != nMap.end() )
                break;
            
            nMap[n] = true;
            
        }
        
        return happyNum;
        
    }
};