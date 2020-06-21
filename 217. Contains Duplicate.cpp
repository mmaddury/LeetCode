class Solution {
public:
    bool 
    containsDuplicate(vector<int>& nums) {
    
        map<int, bool> cMap;
        for( auto const& i : nums ) {
            if( cMap.find(i) != cMap.end() )
                return true;
            cMap[i] = true;
        }
        
        return false;
        
    }
};