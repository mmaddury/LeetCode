class Solution {
public:
    

    void
    genSubsets( vector<int>& v, vector<int>& subset, int index, vector<vector<int>>& r ) {

        r.push_back(subset);
                
        /*
        cout << "index:" << index << " :: [";
        for( auto const& t : subset ) {
            cout << t << ",";
        }
        */
        
        for( int i=index; i<v.size(); i++ ) {           
            subset.push_back(v[i]);
        
            // Recursive call to build subset and
            // go down further into the tree
            genSubsets( v, subset, i+1, r );

            // This is to backtrack
            subset.pop_back();
        }
        
        return;
    }
    
   
        
    vector<vector<int>> 
    subsetsWithDup(vector<int>& nums) {

        // nums = {1, 2, 3};
        
        sort(nums.begin(), nums.end());
        
        // Set up result vector
        vector<vector<int>> r;
        
        // Use a stack for backtracking
        vector<int> subset;
        
        // Generated all subsets
        genSubsets(nums, subset, 0, r);
        
        // Remove duplicates via set
        set<vector<int>> s;
        for( auto const& row : r ) {
            s.insert(row);
        }
        
        // Copy back to vector<vector<int>>
        r.clear();
        for( auto const& row : s ) {
            r.push_back(row);
        }
        
        return r;
        
    }
};

