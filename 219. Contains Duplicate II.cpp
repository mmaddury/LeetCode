class Solution {
public:
    void
    showVec( const vector<int>& v ) {
        cout << "[";
        for( auto const& i : v )
            cout << i << ",";
        cout << "]" << endl;
    }
    
    
    bool 
    containsNearbyDuplicate(vector<int>& nums, int k) {
    
        // showVec(nums1);
        // cout << k << endl;
        
        map<int,size_t> distMap;
        
        for( size_t i=0; i<nums.size(); i++ ) {
            
            /*
            for( auto const& [k,v] : distMap )
                cout << "[" << k << "," << v << "]" << " ";
            cout << endl;
            */
            
            if( distMap.find(nums[i]) != distMap.end() ) {
                // cout << "[" << nums[i] << "," << distMap[nums[i]] << "]" << endl;
                // cout << k << " " << i << endl;
                if( i - distMap[nums[i]] <= k )
                    return true;
                else
                    distMap[nums[i]] = i;
            } else 
                distMap[nums[i]] = i;
        }
        
        return false;
        
    }
};