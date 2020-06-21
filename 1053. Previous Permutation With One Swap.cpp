class Solution {
public:
    
    int
    findNextLargest( const vector<int>& A, int k ) {
        int tIdx = k;
        int tVal = A[k];
        int cVal = 0;
        int cIdx = -1;
        for( int i=A.size()-1; i>k; i-- ) {
            if( A[i] > cVal && A[i] < tVal ) {
                cVal = A[i];
                cIdx = i;
            }
        }
        cout << "k cIdx " << k << " " << cIdx << endl;
        return cIdx;
    }
    
    
    void
    swap( vector<int>& A, int i, int j ) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
    
    
    vector<int> 
    prevPermOpt1(vector<int>& A) {
                
        if( A.size() < 2 )
            return A;
        
        
        //A = {4,2};
        //A = {9, 9, 8, 7, 1};
        //A = {1, 9, 8, 3, 1, 5, 6};
            
        
        // Not sure how to apply greedy approach
        
        // First find the left most index which can be swapped. 
        // If the array if order in non-decreasing you will end 
        // with left < 0. Ow, left point to the largest place
        // value that can be swapped with a lower value
        int left = A.size()-2;
        while( left >=0 && ( A[left+1] >= A[left] ) )
            left--;
        if( left < 0 )
            return A;
        

        // Left points to a place value such that left+1 is larger than left
        // but left is smaller than left-1. 
        
        int right = A.size()-1;
        while( A[right] >= A[left] )
            right--;
        
        // Right points to the largest place value still smaller than left
        // But there could be a string of same values to the left and we
        // want to pick the left most
        // 1 3 2 2 2 6 8
        //     ^
        while( A[right] == A[right-1] )
            right--;
        
        swap(A, left, right);
        
        return A;
        
    }
};