class Solution {
public:
    int 
    searchInsert(vector<int>& nums, int target) {
    
        auto it = std::find(nums.begin(), nums.end(), target);
        
        if( it == nums.end() ) {
            int i=0;
            for( auto const& n : nums ) {
                if( n < target ) {
                    i++;
                }
            }
            return i;
        } else {
            int i = std::distance(nums.begin(), it);
            return i;
        }
        
        
        
    }
};