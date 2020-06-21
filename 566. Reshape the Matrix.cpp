class Solution {
public:
    
    vector<int>
    getRowCol( int ir, int ic, int r, int c, int p, int q ) {
    
        int idx = p*c + q;
        int row = idx/ic;
        int col = idx - row*ic;
        
        /*
        cout << "[" << p << "," << q << "] "
             << idx << " [" << row << "," << col 
             << "]" << endl;
        */
        
        vector<int> rVal;
        rVal.push_back(row);
        rVal.push_back(col);
        
        return rVal;
        
    }
    
    
    
    
    vector<vector<int>> 
    matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        int ir = nums.size();
        int ic = nums[0].size();
        
        if( ir*ic != r*c )
            return nums;
        
        vector<vector<int>> rVal(r,vector<int>(c,0));
        
        for( int i=0; i<r; i++ ) {
            for( int j=0; j<c; j++ ) {
                vector<int> tmp = getRowCol( ir, ic, r, c, i, j );
                int nr = tmp[0];
                int nc = tmp[1];
                rVal[i][j] = nums[nr][nc];
            }
        }
        
        return rVal;
        
    }
};